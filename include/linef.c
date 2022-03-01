/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linef.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:47:46 by barcher           #+#    #+#             */
/*   Updated: 2021/04/22 18:17:00 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

t_cord	l_cross(t_line l1, t_line l2)
{
	t_fcord	k;
	t_fcord	b;

	k.x = (float)(l1.p2.y - l1.p1.y) / (float)(l1.p2.x - l1.p1.x);
	k.y = (float)(l2.p2.y - l2.p1.y) / (float)(l2.p2.x - l2.p1.x);
	b.x = (float)l1.p1.y - k.x * (float)l1.p1.x;
	b.y = (float)l2.p1.y - k.y * (float)l2.p1.x;
	if (k.y > 1.0 || k.y < -1.0)
	{
		if (isinf(k.y))
			l1.p1.x = l2.p1.x;
		else
			l1.p1.x = (b.y - b.x) / (k.x - k.y);
		l1.p1.y = k.x * (float)l1.p1.x + b.x;
	}
	else
	{
		if (isinf(k.x))
			l1.p1.x = l1.p1.x;
		else
			l1.p1.x = (b.y - b.x) / (k.x - k.y);
		l1.p1.y = k.y * (float)l1.p1.x + b.y;
	}
	return (l1.p1);
}

int	l_check(t_line l1, t_line l2)
{
	t_cord	xy;

	xy = l_cross(l1, l2);
	if (xy.x > imax(l2.p1.x, l2.p2.x) || xy.x < imin(l2.p1.x, l2.p2.x)
		|| xy.y > imax(l2.p1.y, l2.p2.y) || xy.y < imin(l2.p1.y, l2.p2.y))
		return (0);
	if (xy.x > imax(l1.p1.x, l1.p2.x) || xy.x < imin(l1.p1.x, l1.p2.x)
		|| xy.y > imax(l1.p1.y, l1.p2.y) || xy.y < imin(l1.p1.y, l1.p2.y))
		return (0);
	return (1);
}
