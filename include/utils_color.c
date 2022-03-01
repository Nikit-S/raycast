/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:31:14 by barcher           #+#    #+#             */
/*   Updated: 2021/04/27 18:47:34 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	count_c(char *str, char *c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (ft_strchr(c, str[i]))
			count++;
		i++;
	}
	return (count);
}

int	get_color(t_data *data, int x, int y)
{
	return (*(unsigned int *)(data->addr + (y * data->ll
			+ x * (data->bpp / 8))));
}

int	set_res(char *str, t_txtr *txtr)
{
	int		x;
	int		y;

	if (*sk_sp(sk_sp(sk_sp(sk_sp(str + 1, " "),
					"0123456789"), " "), "0123456789"))
		return (-1);
	x = ft_atoi(str + 1);
	txtr->res.x = x;
	str = sk_sp(sk_sp(sk_sp(str + 1, " "), "0123456789"), " ");
	y = ft_atoi(str);
	txtr->res.y = y;
	if (!x || !y || !ft_isdigit(str[ft_strlen(str) - 1]))
		return (-1);
	return (1);
}

int	color_conv(char *col)
{
	int	ret;
	int	temp;

	if (!col_cor(col))
		return (0);
	ret = 255;
	ret <<= 8;
	temp = ft_atoi(col);
	if (temp > 255)
		return (0);
	ret += temp;
	ret <<= 8;
	temp = ft_atoi(ft_strchr(col, ',') + 1);
	if (temp > 255)
		return (0);
	ret += temp;
	ret <<= 8;
	temp = ft_atoi(ft_strchr(ft_strchr(col, ',') + 1, ',') + 1);
	if (temp > 255)
		return (0);
	ret += temp;
	return (ret);
}

int	set_textures(t_data *t, t_vars *v, char *path)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	if (!ft_strnstr(path + ft_strlen(path) - 4, ".xpm", 5))
		return (-1);
	while (path[i] && path[i] == ' ')
		i++;
	ret = open(path + i, O_RDONLY);
	close(ret);
	if (ret < 0)
		return (ret);
	t->img = mlx_xpm_file_to_image(v->mlx, path + i, &t->xy.x, &t->xy.y);
	t->addr = mlx_get_data_addr(t->img, &t->bpp, &t->ll, &t->end);
	return (ret);
}
