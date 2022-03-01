/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:47:50 by barcher           #+#    #+#             */
/*   Updated: 2020/10/27 10:50:57 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ret;
	size_t		i;
	char		*pt;

	i = 0;
	ret = malloc(nmemb * size);
	if (ret == 0)
		return (NULL);
	pt = (char *)ret;
	while (i < nmemb * size)
	{
		pt[i] = 0;
		i++;
	}
	return (ret);
}
