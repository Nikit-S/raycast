/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:07:16 by barcher           #+#    #+#             */
/*   Updated: 2021/04/17 15:25:50 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;

	if (!haystack || !needle
		|| ft_strlen(haystack) < ft_strlen(needle) || ft_strlen(needle) > len)
		return (NULL);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	while (i < len && len - i >= ft_strlen(needle))
	{
		if (!ft_strncmp(haystack + i, needle, ft_strlen(needle)))
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
