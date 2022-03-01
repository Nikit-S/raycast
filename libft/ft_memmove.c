/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:00:27 by barcher           #+#    #+#             */
/*   Updated: 2020/11/12 22:12:49 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	signed char	*ptd;
	signed char	*pts;
	signed char	*ptdr;
	signed char	*ptsr;

	if (!dest || !src)
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
