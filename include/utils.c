/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:29:30 by barcher           #+#    #+#             */
/*   Updated: 2021/04/23 00:03:36 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

float	ang_cor(float ca, float add)
{
	ca += add;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	return (ca);
}

void	my_mlx_pixel_put(t_info *inf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > inf->txtr.res.x || y > inf->txtr.res.y)
		return ;
	dst = inf->bckg.addr + (y * inf->bckg.ll + x * (inf->bckg.bpp / 8));
	*(unsigned int *) dst = color;
}
