/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:24:13 by barcher           #+#    #+#             */
/*   Updated: 2021/04/17 15:58:02 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove_g(void *dest, const void *src, size_t n)
{
	signed char	*ptd;
	signed char	*pts;
	signed char	*ptdr;
	signed char	*ptsr;

	if (!dest && !src)
		return (NULL);
	ptd = (signed char *)dest;
	pts = (signed char *)src;
	ptdr = (signed char *)dest + n - 1;
	ptsr = (signed char *)src + n - 1;
	if (ptd < pts)
	{
		while (n--)
			*ptd++ = *pts++;
	}
	else
	{
		while (n--)
			*ptdr-- = *ptsr--;
	}
	return (dest);
}

size_t	ft_strlen_g(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_g(const char *s, int c)
{
	int		i;
	char	*pt;

	if (!s)
		return (NULL);
	pt = (char *)s;
	i = 0;
	while (pt[i])
	{
		if (pt[i] == c)
			return (&pt[i]);
		i++;
	}
	if (pt[i] == c)
		return (&pt[i]);
	return (NULL);
}

size_t	ft_strlcat_g(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen_g(dst);
	len = ft_strlen_g(dst);
	if (size <= len)
		return (ft_strlen_g(src) + size);
	while (j < (size - len - 1) && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (len + ft_strlen_g(src));
}

char	*ft_strjoin_g(char *s1, char const *s2)
{
	char	*ret;
	int		sz1;
	int		sz2;

	if (!s2)
		return (NULL);
	if (s1)
		sz1 = ft_strlen_g(s1);
	else
		sz1 = 0;
	sz2 = ft_strlen_g(s2);
	ret = malloc(sizeof(char) * (sz1 + sz2 + 1));
	if (ret == NULL)
		return (NULL);
	ret[0] = 0;
	ft_strlcat_g(ret, s1, sz1 + 1);
	ft_strlcat_g(ret, s2, (sz1 + sz2 + 1));
	if (s1)
		free(s1);
	return (ret);
}
