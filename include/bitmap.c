/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:24:12 by barcher           #+#    #+#             */
/*   Updated: 2021/04/18 12:32:09 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

unsigned int	*bmp_header(t_info *inf)
{
	unsigned int	*bmpu;

	bmpu = malloc(sizeof(unsigned int ) * 14);
	bmpu[0] = 0x4d420000;
	bmpu[1] = 54 + 3 * inf->txtr.res.x * inf->txtr.res.y;
	bmpu[2] = 0;
	bmpu[3] = 54;
	bmpu[4] = 40;
	bmpu[5] = inf->txtr.res.x;
	bmpu[6] = inf->txtr.res.y;
	bmpu[7] = 0x00180001;
	bmpu[8] = 0;
	bmpu[9] = 3 * inf->txtr.res.x * inf->txtr.res.y;
	bmpu[10] = 0;
	bmpu[11] = 0;
	bmpu[12] = 0;
	bmpu[13] = 0;
	return (bmpu);
}

void	bmp_save(t_info *inf)
{
	int				fd;
	unsigned int	*bmpu;
	unsigned char	pixel[3];
	t_cord			xy;

	fd = open("t.bmp", O_CREAT | O_WRONLY | O_APPEND | O_TRUNC, 0666);
	bmpu = bmp_header(inf);
	write(fd, (char *)bmpu + 2, 54);
	xy.x = -1;
	xy.y = inf->txtr.res.y + 1;
	while (--xy.y > 0)
	{
		while (++xy.x < inf->txtr.res.x)
		{
			pixel[0] = get_color(&inf->bckg, xy.x, xy.y) % 256;
			pixel[1] = (get_color(&inf->bckg, xy.x, xy.y) >> 8) % 256;
			pixel[2] = (get_color(&inf->bckg, xy.x, xy.y) >> 16) % 256;
			write(fd, pixel, 3);
		}
		write(fd, "\0\0\0", inf->txtr.res.x % 4);
		xy.x = -1;
	}
	close(fd);
	free(bmpu);
}
