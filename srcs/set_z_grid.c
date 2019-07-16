/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_z_grid.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 13:51:43 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/16 20:45:41 by jdunnink      ########   odam.nl         */
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

void	set_z_grid(t_object *obj)
{
	obj->z_grid = ft_lstmap(obj->scale, &refer);
	printf("	sorting z_grid list....\n");
	obj->z_grid = merge_sort_list(obj->z_grid);
}