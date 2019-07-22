/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_x_grid.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 13:36:52 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/19 09:27:48 by jdunnink      ########   odam.nl         */
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

void			set_x_grid(t_object *obj)
{
	obj->x_grid = ft_lstmap(obj->scale, &refer);
	set_breaks(obj->x_grid, 'x');
}
