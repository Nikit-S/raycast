/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:59:29 by barcher           #+#    #+#             */
/*   Updated: 2020/11/12 22:13:36 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*pt;
	char	*ptd;

	if (!n || !s1 || !s2)
		return (0);
	i = 0;
	pt = (char *)s1;
	ptd = (char *)s2;
	while (i < n - 1 && (unsigned char)pt[i] - (unsigned char)ptd[i] == 0)
		i++;
	return ((unsigned char)pt[i] - (unsigned char)ptd[i]);
}
