/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:17:07 by barcher           #+#    #+#             */
/*   Updated: 2021/04/27 17:33:44 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# define PI 3.141592
# define PI2 1.570796
# define PI3 4.712388
# define DGR 0.017453

typedef struct s_map
{
	int		mapx;
	int		mapy;
	int		maps;
	int		mapl;
	char	*map;
	int		correct;
}				t_map;

typedef struct s_cord
{
	int	x;
	int	y;
}				t_cord;

typedef struct s_fcord
{
	float	x;
	float	y;
}				t_fcord;

typedef struct s_line
{
	t_cord	p1;
	t_cord	p2;
}				t_line;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		end;
	int		color;
	t_cord	xy;
}				t_data;

typedef struct s_pl
{
	t_cord	xy;
	t_cord	cxy;
	float	dx;
	float	dy;
	float	an;
	int		sz;
	int		color;
}				t_pl;
typedef struct s_txtr
{
	t_data	t_wall;
	t_data	n_wall;
	t_data	w_wall;
	t_data	s_wall;
	t_data	e_wall;
	t_data	sprite;
	int		floor;
	int		top;
	t_cord	res;
}				t_txtr;

typedef struct s_ray
{
	float	disx;
	float	disy;
	float	diss;
	float	dish;
	float	r_an;
	t_line	h_l;
	t_line	v_l;
	t_line	t_l;
}				t_ray;

typedef struct s_temp_ray
{
	float	r_y;
	float	r_x;
	float	x0;
	float	y0;
	float	tang;
	int		r_x_e;
	int		r_y_e;
	int		mp;
	int		crs;
}				t_temp_ray;

typedef struct s_info
{
	t_cord	zero;
	t_data	bckg;
	t_vars	vars;
	t_pl	pl;
	t_txtr	txtr;
	t_line	sprite;
	t_map	map;
	float	amp_x;
	int		blck_sz_mp;
}				t_info;

typedef struct s_raycast
{
	int		rays;
	t_line	temp;
	float	dgr;
	t_ray	ray;
	t_list	*sp_l;
	t_list	*temp_l;
}				t_raycast;

int				imax(int a, int b);
int				imin(int a, int b);
t_cord			ft_cen(t_cord a, t_cord b);
int				color_conv(char *col);
float			dist(t_cord a, t_cord b, int mapl);
int				get_color(t_data *data, int x, int y);
t_map			parser(char *file, t_txtr *t, t_vars *v);
int				set_res(char *str, t_txtr *txtr);
int				color_conv(char *col);
int				set_textures(t_data *t, t_vars *v, char *path);
int				line_parse(t_map *map, t_txtr *txtr, t_vars *vars);
float			ang_cor(float ca, float add);
t_line			amp_line(t_line p, float x);
t_cord			amp_cord(t_cord p, float x);
void			set_globals(t_info *inf);
void			my_mlx_pixel_put(t_info *inf, int x, int y, int color);
void			sqr(t_info *inf, t_line cord, int color);
void			line(t_info *inf, t_line s, int color);
void			move_player(int keycode, t_info *inf);
void			wall_cross(t_temp_ray *t_r, t_info *inf);
t_line			horizontal_ray(t_ray *ray, t_info *inf);
t_line			vertical_ray(t_ray *ray, t_info *inf);
void			wall_glob(int bl, t_info *inf);
void			choose_wall_txtr(t_ray *ray, t_txtr *txtr);
void			draw_wall_line(t_raycast *rcst, t_info *inf);
t_cord			l_cross(t_line l1, t_line l2);
int				l_check(t_line l1, t_line l2);
void			list_sort(t_list **l, t_pl pl, t_map map);
t_line			sprite_dr(int i, t_info *inf);
void			visible_sprites_add(t_raycast *rcst, t_info *inf);
void			draw_sprite_line(t_raycast *rcst, t_info *inf);
void			place_player(t_map map, t_pl *pl);
void			ray_math(t_ray *ray, t_info *inf);
void			bmp_save(t_info *inf);
char			*sk_sp(char *str, char *sk);
void			check_map(t_map *map);
int				count_c(char *str, char *c);
int				col_cor(char *col);
t_line			choose_ray(t_ray *ray);
int				hack_cycle(t_map *map, int i, t_txtr *txtrs, t_vars *vars);
#endif
