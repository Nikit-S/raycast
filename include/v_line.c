/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_line.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:36:49 by barcher           #+#    #+#             */
/*   Updated: 2021/04/17 11:37:31 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	v_r_decide(t_temp_ray *t_r, float r_an, int mapl, t_pl pl)
{
	if (r_an > PI2 && r_an < PI3)
	{
		t_r->r_x = pl.xy.x / 100 * 100 - 1;
		t_r->r_y = (pl.xy.x - t_r->r_x) * t_r->tang + pl.xy.y;
		t_r->x0 = -100;
		t_r->y0 = -t_r->x0 * t_r->tang;
	}
	if (r_an < PI2 || r_an > PI3)
	{
		t_r->r_x = pl.xy.x / 100 * 100 + 100;
		t_r->r_y = (pl.xy.x - t_r->r_x) * t_r->tang + pl.xy.y;
		t_r->x0 = 100;
		t_r->y0 = -t_r->x0 * t_r->tang;
	}
	if (r_an == 0 || r_an == PI)
	{
		t_r->r_x = pl.xy.x;
		t_r->r_y = pl.xy.y;
		t_r->crs = mapl;
	}
}

t_line	vertical_ray(t_ray *ray, t_info *inf)
{
	t_line		v_l;
	t_temp_ray	t_r;

	t_r.tang = -tan(ray->r_an);
	t_r.crs = 0;
	v_r_decide(&t_r, ray->r_an, inf->map.mapl, inf->pl);
	wall_cross(&t_r, inf);
	v_l.p2 = inf->pl.xy;
	v_l.p1.x = t_r.r_x;
	v_l.p1.y = t_r.r_y;
	return (v_l);
}
