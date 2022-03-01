/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:02:18 by barcher           #+#    #+#             */
/*   Updated: 2020/11/12 21:59:52 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	int		n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	ret = malloc(sizeof(char) * (n + 1));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s, n + 1);
	return (ret);
}
