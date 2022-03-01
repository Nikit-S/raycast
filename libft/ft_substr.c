/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:02:17 by barcher           #+#    #+#             */
/*   Updated: 2020/11/12 22:07:10 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start,
size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (len <= 0 || start >= ft_strlen(s))
		len = 0;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (i < len && s[(size_t)start + i])
	{
		ret[i] = s[(size_t)start + i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
