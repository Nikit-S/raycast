/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:47:18 by barcher           #+#    #+#             */
/*   Updated: 2020/11/12 22:16:35 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*pt;

	if (!s)
		return ;
	i = 0;
	pt = (char *)s;
	while (i < n)
	{
		pt[i] = 0;
		i++;
	}
}
