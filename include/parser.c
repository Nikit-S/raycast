/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:41:29 by barcher           #+#    #+#             */
/*   Updated: 2021/04/27 17:49:22 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	line_parse(t_map *map, t_txtr *txtr, t_vars *vars)
{
	int		ret;
	char	*str;

	ret = 0;
	str = map->map;
	if (!ft_strncmp(str, "R ", 2))
		ret = set_res(str, txtr);
	else if (!ft_strncmp(str, "S ", 2))
		ret = set_textures(&(txtr->sprite), vars, ft_strchr(str, ' '));
	else if (!ft_strncmp(str, "F ", 2))
		txtr->floor = color_conv(ft_strchr(str, ' '));
	else if (!ft_strncmp(str, "C ", 2))
		txtr->top = color_conv(ft_strchr(str, ' '));
	else if (!ft_strncmp(str, "NO ", 3))
		ret = set_textures(&txtr->n_wall, vars, ft_strchr(str, ' '));
	else if (!ft_strncmp(str, "SO ", 3))
		ret = set_textures(&txtr->s_wall, vars, ft_strchr(str, ' '));
	else if (!ft_strncmp(str, "WE ", 3))
		ret = set_textures(&txtr->w_wall, vars, ft_strchr(str, ' '));
	else if (!ft_strncmp(str, "EA ", 3))
		ret = set_textures(&txtr->e_wall, vars, ft_strchr(str, ' '));
	else
		return (-1);
	map->correct++;
	return (ret);
}

int	count_lines(t_map *map, char *file, t_txtr *txtrs, t_vars *vars)
{
	int	i;
	int	fd;

	fd = open(file, O_RDONLY);
	i = 0;
	map->mapy = 0;
	while (get_next_line(fd, &map->map) > 0)
	{
		i = hack_cycle(map, i, txtrs, vars);
		free(map->map);
	}
	i = hack_cycle(map, i, txtrs, vars);
	free(map->map);
	close(fd);
	if (map->correct != 9 || i == 0)
		map->correct = 0;
	return (i);
}

void	map_fill(t_map *map, char *file, int i)
{
	char	*temp;
	int		fd;

	map->maps = map->mapx * map->mapy;
	map->map = malloc(sizeof(char) * (map->maps + 1));
	ft_bzero(map->map, map->maps + 1);
	fd = open(file, O_RDONLY);
	while (i-- > 0)
		get_next_line(fd, NULL);
	while (get_next_line(fd, &temp) > 0)
	{
		ft_strlcat(map->map, temp, ft_strlen(temp) + ft_strlen(map->map) + 1);
		i = ft_strlen(temp);
		while (i++ < map->mapx && temp[0])
			ft_strlcat(map->map, " ", ft_strlen(map->map) + 2);
		free(temp);
	}
	ft_strlcat(map->map, temp, ft_strlen(temp) + ft_strlen(map->map) + 1);
	i = ft_strlen(temp);
	while (i++ < map->mapx && temp[0])
		ft_strlcat(map->map, " ", ft_strlen(map->map) + 2);
	free(temp);
	close(fd);
	check_map(map);
}

t_map	parser(char *file, t_txtr *txtrs, t_vars *vars)
{
	int		i;
	t_map	map;

	map.correct = 1;
	map.mapx = 0;
	map.mapy = 0;
	map.mapl = 0;
	txtrs->top = 1;
	txtrs->floor = 1;
	if (!ft_strnstr(file + ft_strlen(file) - 4, ".cub", 4))
		map.correct = 0;
	i = count_lines(&map, file, txtrs, vars);
	if (map.correct == 0 || !i)
		return (map);
	map_fill(&map, file, i);
	if (map.correct == 0)
		return (map);
	while (ft_strchr(map.map, ' '))
		*ft_strchr(map.map, ' ') = '1';
	map.mapl = map.mapy;
	if (map.mapx > map.mapy)
		map.mapl = map.mapx;
	return (map);
}
