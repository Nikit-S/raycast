/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:22:20 by barcher           #+#    #+#             */
/*   Updated: 2021/04/24 14:07:06 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_free(char **ret, int n)
{
	if (ret)
		free(*ret);
	*ret = 0;
	return (n);
}

int	ft_cycle_buf(int fd, char **ret)
{
	int		n;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	n = 0;
	buf[0] = 0;
	while (!ft_strchr_g(*ret, 10))
	{
		n = read(fd, buf, (size_t)BUFFER_SIZE);
		if (n == 0)
		{
			buf[0] = 0;
			break ;
		}
		else if (n < 0)
			return (ft_free(&buf, -1));
		buf[n] = 0;
		*ret = ft_strjoin_g(*ret, buf);
		if (!(*ret))
			return (ft_free(&buf, -1));
	}
	return (ft_free(&buf, n));
}

int	get_next_line(int fd, char **line)
{
	static char	*ret;
	char		*temp;
	int			size;

	if (BUFFER_SIZE <= 0 || fd < 0 || ft_cycle_buf(fd, &ret) < 0)
		return (-1);
	size = ft_strlen_g(ret) - ft_strlen_g(ft_strchr_g(ret, 10));
	temp = malloc(sizeof(char) * (size + 1));
	temp[0] = 0;
	ft_strlcat_g(temp, ret, size + 1);
	if (line)
		*line = temp;
	else
		free(temp);
	if (!ft_strlen_g(ret))
		return (ft_free(&ret, 0));
	if (ft_strchr_g(ret, 10))
		ft_memmove_g(ret, ft_strchr_g(ret, 10) + 1,
			ft_strlen_g(ft_strchr_g(ret, 10)));
	else
		return (ft_free(&ret, 0));
	return (1);
}
