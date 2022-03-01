/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 23:29:19 by barcher           #+#    #+#             */
/*   Updated: 2021/04/23 11:16:29 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

t_line	sprite_dr(int i, t_info *inf)
{
	int		line_l;
	t_line	s;
	t_cord	tri;
	float	k;

	line_l = (float)(inf->pl.sz) *1.7;
	inf->sprite.p1.x = i % inf->map.mapx * 100 + 100 / 2;
	inf->sprite.p1.y = i / inf->map.mapx * 100 + 100 / 2;
	k = ((float)(inf->sprite.p1.y - inf->pl.xy.y)
			/ (float)(inf->sprite.p1.x - inf->pl.xy.x + 0.0001));
	k = atan(k);
	k = ang_cor(k, PI);
	tri.x = sin(k) * (float)line_l;
	tri.y = cos(k) * (float)line_l;
	s.p1.x = inf->sprite.p1.x - tri.x;
	s.p2.x = inf->sprite.p1.x + tri.x;
	s.p1.y = inf->sprite.p1.y + tri.y;
	s.p2.y = inf->sprite.p1.y - tri.y;
	inf->sprite.p2.x = inf->pl.xy.x;
	inf->sprite.p2.y = inf->pl.xy.y;
	return (s);
}

void	visible_sprites_add(t_raycast *rcst, t_info *inf)
{
	t_cord	xy;
	t_line	*spriter;
	t_cord	fu;

	xy.x = -1;
	xy.y = -1;
	fu.x = 0;
	while (++xy.y < inf->map.mapy)
	{
		while (++xy.x < inf->map.mapx)
		{
			fu.y = xy.y * inf->map.mapx + xy.x;
			if (fu.y > 0 && fu.y < inf->map.maps && inf->map.map[fu.y] == '2'
				&& l_check(rcst->ray.t_l, sprite_dr(fu.y, inf)))
			{
				fu.x = 1;
				spriter = malloc(sizeof(t_line));
				*spriter = sprite_dr(fu.y, inf);
				ft_lstadd_back(&rcst->sp_l, ft_lstnew(spriter));
			}
		}
		xy.x = -1;
	}
	if (fu.x)
		list_sort(&rcst->sp_l, inf->pl, inf->map);
}

static void	hack(t_raycast *rcst, t_info *inf, 	t_cord *spriter, t_fcord *fxy)
{
	rcst->ray.diss = dist(l_cross(rcst->temp, rcst->ray.t_l), inf->pl.xy,
			inf->map.mapl) * cos(inf->pl.an - rcst->ray.r_an);
	fxy->y = 0;
	fxy->x = (float)dist(l_cross(rcst->temp, rcst->ray.t_l), rcst->temp.p1,
			inf->map.mapl) / (float)dist(rcst->temp.p1, rcst->temp.p2,
			inf->map.mapl) * (float)inf->txtr.sprite.xy.x;
	spriter->x = rcst->rays;
	if ((ft_cen(rcst->temp.p1, rcst->temp.p2)).x < inf->pl.xy.x)
		fxy->x = inf->txtr.sprite.xy.x - fxy->x;
}

void	draw_sprite_line(t_raycast *rcst, t_info *inf)
{
	int		spriteh;
	t_cord	spriter;
	t_fcord	fxy;
	int		sprite_y;
	float	ty_step;

	hack(rcst, inf, &spriter, &fxy);
	spriteh = (float)inf->txtr.sprite.xy.y * (float)inf->txtr.res.y
		/ rcst->ray.diss / 3;
	ty_step = (float)inf->txtr.sprite.xy.y / (float)spriteh;
	sprite_y = -1;
	while (++sprite_y <= spriteh && dist(l_cross(rcst->temp, rcst->ray.t_l),
			inf->pl.xy, inf->map.mapl) < dist(rcst->ray.t_l.p1,
			rcst->ray.t_l.p2, inf->map.mapl) && dist(l_cross(rcst->temp,
				rcst->ray.h_l), inf->pl.xy, inf->map.mapl)
		< dist(rcst->ray.h_l.p1, rcst->ray.t_l.p2, inf->map.mapl))
	{
		spriter.y = sprite_y + inf->txtr.res.y / 2 - spriteh / 4;
		if ((unsigned int)get_color(&inf->txtr.sprite, fxy.x, fxy.y)
			!= 0xff000000)
			my_mlx_pixel_put(inf, spriter.x, spriter.y,
				get_color(&inf->txtr.sprite, fxy.x, fxy.y));
		fxy.y += ty_step;
	}
}
