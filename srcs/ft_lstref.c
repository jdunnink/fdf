/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstref.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 18:51:42 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/17 18:52:57 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	t_list	*refer(t_list *elem)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		error(7);
	new->content = elem->content;
	new->content_size = elem->content_size;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstref(t_list *src)
{
	t_list	*dest;
	t_list	*iter;
	t_list	*next;

	iter = refer(src);
	dest = iter;
	src = src->next;
	while (src)
	{
		next = refer(src);
		iter->next = next;
		iter = next;
		src = src->next;
	}
	return (dest);
}