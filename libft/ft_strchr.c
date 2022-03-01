/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:01:19 by barcher           #+#    #+#             */
/*   Updated: 2020/11/15 14:33:26 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
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
