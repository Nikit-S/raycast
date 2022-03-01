/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:00:50 by barcher           #+#    #+#             */
/*   Updated: 2020/11/12 22:12:32 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, int n)
{
	int		i;
	char	*pt;

	if (!s)
		return (NULL);
	i = 0;
	pt = (char *)s;
	while (i < n)
	{
		pt[i] = c;
		i++;
	}
	return (s);
}
