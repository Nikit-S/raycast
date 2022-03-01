/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:14:13 by barcher           #+#    #+#             */
/*   Updated: 2021/04/27 19:03:31 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_cub3d.h"

void	raycaster_init(t_raycast *rcst, t_info *inf)
{
	t_line	scr;

	scr.p1 = inf->txtr.res;
	scr.p2 = inf->zero;
	rcst->rays = 0.0;
	rcst->dgr = 60.0 * DGR / inf->txtr.res.x;
	rcst->ray.r_an = inf->pl.an - DGR * 30.0;
	rcst->ray.r_an = ang_cor(rcst->ray.r_an, 0.0);
	rcst->sp_l = NULL;
	sqr(inf, scr, inf->txtr.top);
}

void	raycaster(t_info *inf)
{
	t_raycast	rcst;

	raycaster_init(&rcst, inf);
	while (rcst.rays < inf->txtr.res.x)
	{
		rcst.temp.p1.x = 0;
		ray_math(&rcst.ray, inf);
		draw_wall_line(&rcst, inf);
		rcst.ray.t_l = choose_ray(&rcst.ray);
		visible_sprites_add(&rcst, inf);
		rcst.temp_l = rcst.sp_l;
		while (rcst.temp_l)
		{
			rcst.temp = *(t_line *)rcst.temp_l->content;
			draw_sprite_line(&rcst, inf);
			rcst.temp_l = rcst.temp_l->next;
		}
		ft_lstclear(&rcst.sp_l, free);
		rcst.sp_l = NULL;
		rcst.ray.r_an = ang_cor(rcst.ray.r_an, rcst.dgr);
		rcst.rays++;
	}
}

int	key_hook(int keycode, t_info *inf)
{
	move_player(keycode, inf);
	if (keycode == 65307)
		mlx_destroy_window(inf->vars.mlx, inf->vars.win);
	if (keycode == 65307)
		exit (0);
	raycaster(inf);
	mlx_put_image_to_window(inf->vars.mlx, inf->vars.win, inf->bckg.img, 0, 0);
	return (0);
}

int	game_init(int argi, char *argc[], t_info *inf)
{
	t_cord	xy;

	if (argi < 2 || argi > 3)
		return (0);
	inf->zero.x = 0;
	inf->zero.y = 0;
	inf->vars.mlx = mlx_init();
	mlx_get_screen_size(inf->vars.mlx, &xy.x, &xy.y);
	inf->map = parser(argc[1], &inf->txtr, &inf->vars);
	if (inf->map.correct == 0 || inf->txtr.res.x < 0 || inf->txtr.res.y < 0)
		ft_putstr_fd("Error\nCheck your cub file\n", 1);
	if (inf->map.correct == 0 || inf->txtr.res.x < 0 || inf->txtr.res.y < 0)
		return (0);
	if (inf->txtr.res.x > xy.x)
		inf->txtr.res.x = xy.x;
	if (inf->txtr.res.y > xy.y)
		inf->txtr.res.y = xy.y;
	inf->blck_sz_mp = 400 / inf->map.mapl;
	inf->amp_x = (float)inf->blck_sz_mp / 100.0;
	inf->pl.sz = 11;
	inf->pl.color = color_conv("255,255,0");
	inf->pl.dx = cos(inf->pl.an) * inf->pl.sz / 2;
	inf->pl.dy = sin(inf->pl.an) * inf->pl.sz / 2;
	return (1);
}

int	main(int argi, char *argc[])
{
	t_info	inf;

	if (!game_init(argi, argc, &inf))
		exit (0);
	if (argi != 3)
		inf.vars.win = mlx_new_window(inf.vars.mlx, inf.txtr.res.x,
				inf.txtr.res.y, "Raycaster");
	inf.bckg.img = mlx_new_image(inf.vars.mlx, inf.txtr.res.x, inf.txtr.res.y);
	inf.bckg.addr = mlx_get_data_addr(inf.bckg.img,
			&inf.bckg.bpp, &inf.bckg.ll, &inf.bckg.end);
	place_player(inf.map, &inf.pl);
	if (argi != 3)
		mlx_hook(inf.vars.win, 2, 1L << 0, key_hook, &inf);
	raycaster(&inf);
	if (argi != 3)
		mlx_put_image_to_window(inf.vars.mlx, inf.vars.win, inf.bckg.img, 0, 0);
	if (argi == 3 && ft_strncmp(argc[2], "--save", 7) == 0)
	{
		bmp_save(&inf);
		free(inf.map.map);
		exit (0);
	}
	mlx_loop(inf.vars.mlx);
	free(inf.map.map);
	return (0);
}
