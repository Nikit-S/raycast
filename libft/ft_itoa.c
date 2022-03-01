/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:04:19 by barcher           #+#    #+#             */
/*   Updated: 2021/04/17 15:12:48 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_put(char *ret, long int num, int size)
{
	if (num == 0)
	{
		ret[0] = '0';
		return ;
	}
	while (size)
	{
		ret[size - 1] = num % 10 + '0';
		num /= 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	char		*ret;
	long int	num;
	int			min;

	min = 0;
	num = n;
	if (num < 0)
	{
		num *= -1;
		min = 1;
	}
	ret = malloc(sizeof(char) * (count(num) + min + 1));
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, count(num) + min + 1);
	ft_put(ret, num, count(num));
	if (min == 1)
	{
		ft_memmove(ret + 1, ret, count(num));
		ret[0] = '-';
	}
	return (ret);
}
