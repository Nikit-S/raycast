/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:47:13 by barcher           #+#    #+#             */
/*   Updated: 2021/04/19 12:03:15 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long int	ret;
	long int	min;
	int			i;

	i = 0;
	ret = 0;
	if (ft_strlen(nptr) == 0)
		return (0);
	while (ft_strchr(" \t\n\r\v\f", nptr[i]))
		i++;
	min = 1;
	if (nptr[i] == '-')
		min = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i += 1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		ret = ret * 10 + nptr[i++] - '0';
	if ((ret * min > 2147483647 && ret * min != 9223372036854775807L)
		|| ret * min == -9223372036854775807L - 1L)
		return (10000000);
	else if (ret * min < -2147483648)
		return (10000000);
	return ((int)(ret * min));
}
