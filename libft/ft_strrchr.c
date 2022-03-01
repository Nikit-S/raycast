/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:05:41 by barcher           #+#    #+#             */
/*   Updated: 2020/11/12 22:17:02 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ret;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	ret = (char *)s;
	while (i >= 0)
	{
		if (ret[i] == c)
			return (&ret[i]);
		i--;
	}
	return (NULL);
}
