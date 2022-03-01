/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:04:52 by barcher           #+#    #+#             */
/*   Updated: 2020/11/07 13:48:42 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*pt;
	char	*ptd;

	if (!src)
		return (0);
	if (size == 0 || !dst)
		return (ft_strlen(src));
	pt = (char *)src;
	ptd = (char *)dst;
	i = 0;
	while (pt[i] && i < size - 1)
	{
		ptd[i] = pt[i];
		i++;
	}
	ptd[i] = 0;
	return (ft_strlen(src));
}
