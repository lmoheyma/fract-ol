/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 05:12:55 by lmoheyma          #+#    #+#             */
/*   Updated: 2023/12/10 05:35:59 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

t_tmplst	*lastnode(t_tmplst *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_tmplst	*new_node(int x, int y)
{
	t_tmplst	*node;

	node = malloc(sizeof(t_tmplst));
	if (!node)
		return (NULL);
	node->x = x;
	node->y = y;
	node->next = NULL;
	return (node);
}

void	add_node_back(t_tmplst **lst, t_tmplst *new)
{
	t_tmplst	*last;

	if (lst)
	{
		if (*lst)
		{
			last = lastnode(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}