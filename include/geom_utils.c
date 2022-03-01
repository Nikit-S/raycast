/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:45:42 by barcher           #+#    #+#             */
/*   Updated: 2021/04/17 15:39:40 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

t_cord	amp_cord(t_cord p, float x)
{
	t_cord	ret;

	ret.x = (int)((float)p.x * x);
	ret.y = (int)((float)p.y * x);
	return (ret);
}

t_line	amp_line(t_line p, float x)
{
	t_line	ret;

	ret.p1 = amp_cord(p.p1, x);
	ret.p2 = amp_cord(p.p2, x);
	return (ret);
}

void	sqr(t_info *inf, t_line cord, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < cord.p1.y)
	{
		while (x < cord.p1.x)
		{
			cord.p2.x += 1;
			my_mlx_pixel_put(inf, cord.p2.x, cord.p2.y, color);
			x++;
		}
		cord.p2.x -= x;
		x = 0;
		y++;
		cord.p2.y += 1;
	}
}

void	line(t_info *inf, t_line s, int color)
{
	float	x;
	float	y;
	float	b;
	float	c;

	x = imin(s.p1.x, s.p2.x);
	y = imin(s.p1.y, s.p2.y);
	b = imax(s.p1.x, s.p2.x);
	c = imax(s.p1.y, s.p2.y);
	my_mlx_pixel_put(inf, s.p1.x, s.p1.y, color);
	while (x < b && (s.p2.x - s.p1.x) != 0)
	{
		y = (((x - s.p1.x) / (s.p2.x - s.p1.x)) * (s.p2.y - s.p1.y) + s.p1.y);
		my_mlx_pixel_put(inf, x, y, color);
		x += 1;
	}
	x = imin(s.p1.x, s.p2.x);
	y = imin(s.p1.y, s.p2.y);
	while (y < c && s.p2.y - s.p1.y != 0)
	{
		x = (((y - s.p1.y) / (s.p2.y - s.p1.y)) * (s.p2.x - s.p1.x) + s.p1.x);
		my_mlx_pixel_put(inf, x, y, color);
		y += 1;
	}
	my_mlx_pixel_put(inf, s.p2.x, s.p2.y, color);
}
