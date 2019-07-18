/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_x_grid.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 13:36:52 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:35:17 by jdunnink      ########   odam.nl         */
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
	if (obj->total_vectors < 30000)
		obj->x_grid = ft_lstmap(obj->scale, &refer);
	else
		obj->x_grid = ft_lstref(obj->scale);
	set_breaks(obj->x_grid, 'x');
}
