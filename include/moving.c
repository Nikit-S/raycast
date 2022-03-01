/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:39:22 by barcher           #+#    #+#             */
/*   Updated: 2021/04/17 16:50:23 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	s_key(t_info *inf)
{
	int	col_x;
	int	col_y;

	if (inf->pl.dx > 0.0)
		col_x = inf->pl.cxy.x - inf->pl.sz * 2;
	else
		col_x = inf->pl.cxy.x + inf->pl.sz * 2;
	if (inf->pl.dy > 0.0)
		col_y = inf->pl.cxy.y - inf->pl.sz * 2;
	else
		col_y = inf->pl.cxy.y + inf->pl.sz * 2;
	if (inf->map.map[inf->pl.xy.y / 100 * inf->map.mapx + col_x / 100] != '1')
		inf->pl.xy.x = round((float)inf->pl.xy.x - inf->pl.dx);
	if (inf->map.map[col_y / 100 * inf->map.mapx + inf->pl.xy.x / 100] != '1')
		inf->pl.xy.y = round((float)inf->pl.xy.y - inf->pl.dy);
}

void	w_key(t_info *inf)
{
	int	col_x;
	int	col_y;

	if (inf->pl.dx > 0.0)
		col_x = inf->pl.cxy.x + inf->pl.sz * 2;
	else
		col_x = inf->pl.cxy.x - inf->pl.sz * 2;
	if (inf->pl.dy > 0.0)
		col_y = inf->pl.cxy.y + inf->pl.sz * 2;
	else
		col_y = inf->pl.cxy.y - inf->pl.sz * 2;
	if (inf->map.map[inf->pl.xy.y / 100 * inf->map.mapx + col_x / 100] != '1')
		inf->pl.xy.x = round((float)inf->pl.xy.x + inf->pl.dx);
	if (inf->map.map[col_y / 100 * inf->map.mapx + inf->pl.xy.x / 100] != '1')
		inf->pl.xy.y = round((float)inf->pl.xy.y + inf->pl.dy);
}

void	a_key(t_info *inf)
{
	int	col_x;
	int	col_y;

	inf->pl.dx = cos(inf->pl.an - PI2) * 7.0;
	inf->pl.dy = sin(inf->pl.an - PI2) * 7.0;
	if (inf->pl.dx > 0.0)
		col_x = inf->pl.cxy.x - inf->pl.sz * 2;
	else
		col_x = inf->pl.cxy.x + inf->pl.sz * 2;
	if (inf->pl.dy > 0.0)
		col_y = inf->pl.cxy.y - inf->pl.sz * 2;
	else
		col_y = inf->pl.cxy.y + inf->pl.sz * 2;
	if (inf->map.map[inf->pl.xy.y / 100 * inf->map.mapx + col_x / 100] != '1')
		inf->pl.xy.x -= (int)inf->pl.dx;
	if (inf->map.map[col_y / 100 * inf->map.mapx + inf->pl.xy.x / 100] != '1')
		inf->pl.xy.y -= (int)inf->pl.dy;
}

void	d_key(t_info *inf)
{
	int	col_x;
	int	col_y;

	inf->pl.dx = cos(inf->pl.an - PI2) * 7.0;
	inf->pl.dy = sin(inf->pl.an - PI2) * 7.0;
	if (inf->pl.dx > 0.0)
		col_x = inf->pl.cxy.x + inf->pl.sz * 2;
	else
		col_x = inf->pl.cxy.x - inf->pl.sz * 2;
	if (inf->pl.dy > 0.0)
		col_y = inf->pl.cxy.y + inf->pl.sz * 2;
	else
		col_y = inf->pl.cxy.y - inf->pl.sz * 2;
	if (inf->map.map[inf->pl.xy.y / 100 * inf->map.mapx + col_x / 100] != '1')
		inf->pl.xy.x += (int)inf->pl.dx;
	if (inf->map.map[col_y / 100 * inf->map.mapx + inf->pl.xy.x / 100] != '1')
		inf->pl.xy.y += (int)inf->pl.dy;
}

void	move_player(int	keycode, t_info *inf)
{
	inf->pl.cxy.x = inf->pl.xy.x + inf->pl.sz / 2;
	inf->pl.cxy.y = inf->pl.xy.y + inf->pl.sz / 2;
	inf->pl.dx = cos(inf->pl.an) * 7.0;
	inf->pl.dy = sin(inf->pl.an) * 7.0;
	if (keycode == 65363 || keycode == 65361)
		inf->pl.an += (keycode - 65362) / 10.0;
	inf->pl.an = ang_cor(inf->pl.an, 0.0);
	if (keycode == 119)
		w_key(inf);
	if (keycode == 115)
		s_key(inf);
	if (keycode == 100)
		a_key(inf);
	else if (keycode == 97)
		d_key(inf);
}
