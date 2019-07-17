/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_z_grid.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 13:51:43 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/17 20:43:21 by jdunnink      ########   odam.nl         */
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
	if (obj->total_vectors < 30000)
		obj->z_grid = ft_lstmap(obj->scale, &refer);
	else
		obj->z_grid = ft_lstref(obj->scale);
	printf("	sorting z_grid list....\n");
	obj->z_grid = merge_sort_list(obj->z_grid);
	set_breaks(obj->z_grid, 'z');
}