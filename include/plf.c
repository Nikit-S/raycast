/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 23:27:20 by barcher           #+#    #+#             */
/*   Updated: 2021/04/19 14:33:09 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	place_player(t_map map, t_pl *pl)
{
	int	i;

	i = 0;
	while (i < map.maps)
	{
		if (map.map[i] == 'N' || map.map[i] == 'W' || map.map[i] == 'E'
			|| map.map[i] == 'S')
		{
			if (map.map[i] == 'S')
				pl->an = PI2;
			else if (map.map[i] == 'N')
				pl->an = PI3;
			else if (map.map[i] == 'E')
				pl->an = 0;
			else if (map.map[i] == 'W')
				pl->an = PI;
			map.map[i] = '0';
			pl->xy.x = i % map.mapx * 100 + 100 / 2;
			pl->xy.y = i / map.mapx * 100 + 100 / 2;
		}
		i++;
	}
	pl->cxy.x = pl->xy.x + pl->sz / 2;
	pl->cxy.y = pl->xy.y + pl->sz / 2;
}
/*
**void print_map()
**{
**	int x;
**	int y;
**	t_line map_crd;
**
**	x = 0;
**	y = 0;
**	map_crd.p2.x = 0;
**	map_crd.p2.y = 0;
**	map_crd.p1.x = blck_sz_mp - 1;
**	map_crd.p1.y = blck_sz_mp - 1;
**	while(y < map.mapy)
**	{
**		while(x < map.mapx)
**		{
**			if (map.map[y * map.mapx + x] == '1')
**			{
**				sqr(bckg_map, map_crd, 0x00FFFFFF);
**			}
**			else
**			{
**				sqr(bckg_map, map_crd, 0x00000000);
**			}
**			if (map.map[y * map.mapx + x] == '2')
**			{
**				line(bckg_map, amp_line(sprite_dr(y * map.mapx + x), amp_x),
**			0x00FF00FF);
**				line(bckg_map, amp_line(sprite, amp_x), 0x00FF00FF);
**			}
**			x++;
**			map_crd.p2.x += blck_sz_mp;
**		}
**		x = 0;
**		y++;
**		map_crd.p2.x = 0;
**		map_crd.p2.y += blck_sz_mp;
**	}
**	if (map_f)
**		mlx_put_image_to_window(vars_map.mlx, vars_map.win,
**		bckg_map.img, x * blck_sz_mp, y * blck_sz_mp );
**}
*/
