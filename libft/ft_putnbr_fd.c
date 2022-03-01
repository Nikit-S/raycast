/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:08:05 by barcher           #+#    #+#             */
/*   Updated: 2021/04/17 15:17:32 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_writer(unsigned int out, int fd)
{
	char	a;

	if (out > 0)
	{
		ft_writer(out / 10, fd);
		a = out % 10 + '0';
		write(fd, &a, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	out;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	out = n * -1;
	if (n >= 0)
		out = n ;
	if (n < 0)
		write(fd, "-", 1);
	ft_writer(out, fd);
}
