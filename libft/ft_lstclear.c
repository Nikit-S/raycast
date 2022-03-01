/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:09:59 by barcher           #+#    #+#             */
/*   Updated: 2020/11/05 22:05:36 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*start;
	t_list	*end;

	start = *lst;
	if (!lst || !*lst)
		return ;
	while (start)
	{
		end = start;
		del(start->content);
		start = start->next;
		free(end);
	}
	*lst = 0;
}
