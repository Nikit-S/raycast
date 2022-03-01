/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:49:57 by barcher           #+#    #+#             */
/*   Updated: 2021/04/22 18:17:25 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

t_cord	ft_cen(t_cord a, t_cord b)
{
	a.x = (fmax(a.x, b.x) - fmin(a.x, b.x)) / 2 + fmin(a.x, b.x);
	a.y = (fmax(a.y, b.y) - fmin(a.y, b.y)) / 2 + fmin(a.y, b.y);
	return (a);
}

int	decide(t_list *st, t_pl pl, t_map map)
{
	return (dist(ft_cen(((t_line *)st->content)->p1,
				((t_line *)st->content)->p2), pl.xy, map.mapl)
		< dist(ft_cen(((t_line *)st->next->content)->p1,
				((t_line *)st->next->content)->p2), pl.xy, map.mapl));
}

void	list_sort(t_list **l, t_pl pl, t_map map)
{
	t_list	*st;
	t_list	*temp;
	t_cord	excn;

	excn.x = 0;
	while (excn.x == 0)
	{
		excn.x = 1;
		excn.y = 0;
		st = *l;
		while (st->next)
		{
			if (decide(st, pl, map))
			{
				excn.x = 0;
				temp = st->next->content;
				st->next->content = st->content;
				st->content = temp;
			}
			else
				st = st->next;
			excn.y++;
		}
	}
}
