/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:40:26 by barcher           #+#    #+#             */
/*   Updated: 2021/04/17 15:14:56 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_list	*start;
	t_list	*n_list;

	if (!lst)
		return (NULL);
	n_list = 0;
	start = lst;
	while (lst)
	{
		start = ft_lstnew(f(lst->content));
		if (!start)
			ft_lstclear(&n_list, del);
		if (!start)
			return (0);
		ft_lstadd_back(&n_list, start);
		lst = lst->next;
	}
	return (n_list);
}
