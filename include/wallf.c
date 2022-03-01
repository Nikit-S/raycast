/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:38:16 by barcher           #+#    #+#             */
/*   Updated: 2021/04/22 18:12:50 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	wall_cross(t_temp_ray *t_r, t_info *inf)
{
	while (t_r->crs < inf->map.mapl)
	{
		t_r->r_x_e = t_r->r_x / 100;
		t_r->r_y_e = t_r->r_y / 100;
		t_r->mp = t_r->r_y_e * inf->map.mapx + t_r->r_x_e;
		if (t_r->mp >= 0 && t_r->mp < inf->map.maps
			&& inf->map.map[t_r->mp] == '1')
			t_r->crs = inf->map.mapl;
		else
		{
			t_r->r_x += t_r->x0;
			t_r->r_y += t_r->y0;
			t_r->crs += 1;
		}
	}
}

float	wall_x_index(t_ray ray)
{
	float	tx;

	tx = 0;
	if (ray.disy < ray.disx)
	{
		tx = (float)((int)ray.v_l.p1.y % 100) / (float)100 * 32;
		if (ray.r_an > PI2 && ray.r_an < PI3)
			tx = 31 - tx;
	}
	else
	{
		tx = (float)((int)ray.h_l.p1.x % 100) / (float)100 * 32;
		if (ray.r_an < PI)
			tx = 31 - tx;
	}
	if (tx < 0)
		tx *= -1;
	return (tx);
}

void	choose_wall_txtr(t_ray *ray, t_txtr *txtr)
{
	if (ray->disx < ray->disy && ray->r_an > PI)
		txtr->t_wall = txtr->n_wall;
	else if (ray->disx < ray->disy)
		txtr->t_wall = txtr->s_wall;
	if (ray->disy < ray->disx && ray->r_an > PI2 && ray->r_an < PI3)
		txtr->t_wall = txtr->w_wall;
	else if (ray->disy < ray->disx)
		txtr->t_wall = txtr->e_wall;
}

void	draw_wall_line(t_raycast *rcst, t_info *inf)
{
	t_fcord	ty;
	t_fcord	xy;
	t_cord	wall;
	t_cord	lw;

	xy.x = wall_x_index(rcst->ray);
	lw.x = inf->txtr.res.y / rcst->ray.dish * (float)inf->txtr.t_wall.xy.x * 4;
	ty.x = (float)inf->txtr.t_wall.xy.x / (float)lw.x;
	ty.y = 0;
	if (lw.x > inf->txtr.res.y)
		ty.y = (lw.x - inf->txtr.res.y) / 2.0;
	if (lw.x > inf->txtr.res.y)
		lw.x = inf->txtr.res.y;
	xy.y = ty.x * ty.y;
	lw.y = -1;
	while (++lw.y < inf->txtr.res.y)
	{
		wall.y = inf->txtr.res.y / 2.0 - lw.x / 2.0 + lw.y;
		if (lw.y < lw.x)
			my_mlx_pixel_put(inf, rcst->rays, wall.y,
				get_color(&inf->txtr.t_wall, (int)xy.x, (int)xy.y));
		else
			my_mlx_pixel_put(inf, rcst->rays, wall.y, inf->txtr.floor);
		xy.y += ty.x;
	}
}
