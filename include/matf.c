/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:07:37 by barcher           #+#    #+#             */
/*   Updated: 2021/04/22 23:16:20 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	imax(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	imin(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

float	dist(t_cord a, t_cord b, int mapl)
{
	float	ret;

	ret = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
	if (a.x >= 100 * mapl || a.y >= 100 * mapl || a.x <= 0 || a.y <= 0
		|| isnan(ret))
		return (10000000);
	return (ret);
}

t_line	choose_ray(t_ray *ray)
{
	t_line	t_l;

	t_l = ray->v_l;
	return (t_l);
}

void	ray_math(t_ray *ray, t_info *inf)
{
	float	ca;

	ray->h_l = horizontal_ray(ray, inf);
	ray->disx = dist(ray->h_l.p1, inf->pl.xy, inf->map.mapl);
	ray->v_l = vertical_ray(ray, inf);
	ray->disy = dist(ray->v_l.p1, inf->pl.xy, inf->map.mapl);
	choose_wall_txtr(ray, &inf->txtr);
	if (ray->disx < ray->disy)
		ray->dish = ray->disx;
	else
		ray->dish = ray->disy;
	ca = inf->pl.an - ray->r_an;
	ca = ang_cor(ca, 0);
	ray->dish *= cos(ca);
}
