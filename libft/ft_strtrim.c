/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:03:51 by barcher           #+#    #+#             */
/*   Updated: 2021/04/17 15:27:11 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	start(char const *s1, char const *set)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]))
			cnt++;
		else
			break ;
		i++;
	}
	return (cnt);
}

int	end(char const *s1, char const *set)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[ft_strlen(s1) - i - 1]))
			cnt++;
		else
			break ;
		i++;
	}
	return (cnt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	cnts;
	size_t	cnte;

	ret = (char *)s1;
	if (!s1 || !set)
		return (ret);
	cnts = start(s1, set);
	cnte = end(s1, set);
	ret = ft_substr(s1, cnts, ft_strlen(s1) - cnts - cnte);
	return (ret);
}
