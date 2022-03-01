/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:49:05 by barcher           #+#    #+#             */
/*   Updated: 2020/11/12 21:37:37 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*pt;
	char	*ptd;
	char	rc;

	if (!dest || !src)
		return (NULL);
	i = 0;
	pt = (char *)src;
	ptd = (char *)dest;
	rc = (unsigned char)c;
	while (i < n)
	{
		ptd[i] = (unsigned char)pt[i];
		if (ptd[i] == rc)
			break ;
		i++;
	}
	if (ptd[i] != rc)
		return (NULL);
	return ((void *)(ptd + i + 1));
}
