/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_line.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:45:53 by barcher           #+#    #+#             */
/*   Updated: 2021/04/16 22:35:29 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	h_decide(t_temp_ray *t_r, float r_an, int mapl, t_pl pl)
{
	if (r_an > PI)
	{
		t_r->r_y = pl.xy.y / 100 * 100 - 1;
		t_r->r_x = (pl.xy.y - t_r->r_y) * t_r->tang + pl.xy.x;
		t_r->y0 = -100;
		t_r->x0 = -t_r->y0 * t_r->tang;
	}
	if (r_an < PI)
	{
		t_r->r_y = pl.xy.y / 100 * 100 + 100;
		t_r->r_x = (pl.xy.y - t_r->r_y) * t_r->tang + pl.xy.x;
		t_r->y0 = 100;
		t_r->x0 = -t_r->y0 * t_r->tang;
	}
	if (r_an == 0 || r_an == PI)
	{
		t_r->r_x = pl.xy.x;
		t_r->r_y = pl.xy.y;
		t_r->crs = mapl;
	}
}

t_line	horizontal_ray(t_ray *ray, t_info *inf)
{
	t_line		h_l;
	t_temp_ray	t_r;

	t_r.tang = -1 / tan(ray->r_an);
	t_r.crs = 0;
	h_decide(&t_r, ray->r_an, inf->map.mapl, inf->pl);
	wall_cross(&t_r, inf);
	h_l.p2 = inf->pl.cxy;
	h_l.p1.x = t_r.r_x;
	h_l.p1.y = t_r.r_y;
	return (h_l);
}
