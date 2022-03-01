/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:52:08 by barcher           #+#    #+#             */
/*   Updated: 2021/04/27 18:38:35 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	col_cor(char *col)
{
	int	i;
	int	j;

	j = -1;
	if (!ft_strchr(ft_strchr(col, ',') + 1, ',') || *sk_sp(sk_sp(sk_sp(sk_sp(
						sk_sp(sk_sp(col, " "), "0123456789"), " ,"),
					"0123456789"), " ,"), "0123456789"))
		return (0);
	while (++j < 3)
	{
		i = 0;
		col = sk_sp(col, " ");
		if (*col == '0')
			col = sk_sp(col, "0");
		else
		{
			while (ft_isdigit(col[i]))
				i++;
			if (i > 3 || i == 0)
				return (0);
		}
		if (j < 2)
			col = ft_strchr(col, ',') + 1;
	}
	return (1);
}

char	*sk_sp(char *str, char *sk)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr(sk, str[i]))
		i++;
	return (str + i);
}

void	check_map(t_map *map)
{
	t_cord	xy;
	int		mp;

	xy.x = -1;
	xy.y = -1;
	while (++xy.y < map->mapy)
	{
		while (++xy.x < map->mapx)
		{
			mp = xy.y * map->mapx + xy.x;
			if (ft_strchr("2SWEN0", map->map[mp]) && (xy.y == map->mapy - 1
					|| xy.y == 0 || xy.x == 0 || xy.x == map->mapx -1
					|| map->map[mp - 1] == ' ' || map->map[mp + 1] == ' '
					|| map->map[(xy.y - 1) *map->mapx + xy.x] == ' '
					|| map->map[(xy.y + 1) *map->mapx + xy.x] == ' '))
				map->correct = 0;
		}
		xy.x = -1;
	}
	xy.y = 0;
	while (xy.x < map->maps)
		if (ft_isalpha(map->map[xy.x++]))
			xy.y = xy.y + 1;
	if (xy.y != 1)
		map->correct = 0;
}

int	hack_cycle(t_map *map, int i, t_txtr *txtrs, t_vars *vars)
{
	if (map->correct && map->map[0] && ft_strchr("RNSWEFC",
			map->map[0]) && (line_parse(map,
				txtrs, vars) < 0 || !txtrs->floor || !txtrs->top))
		map->correct = 0;
	else if (map->correct && ((map->map[0] && ft_strchr("012",
					*sk_sp(map->map, " "))) || map->mapy != 0))
	{
		if ((size_t)map->mapx < ft_strlen(map->map))
			map->mapx = (int)ft_strlen(map->map);
		map->mapy++;
		i--;
	}
	else if (map->map[0] && !ft_strchr("RNSWEFC", map->map[0]))
		map->correct = 0;
	return (i + 1);
}
