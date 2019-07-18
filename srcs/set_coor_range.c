/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_coor_range.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 19:33:42 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:34:39 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_y_range(t_object *obj)
{
	t_list	*iter;
	t_vec	*curr;
	float	min;
	float	max;

	iter = obj->input;
	curr = iter->content;
	min = curr->y;
	max = curr->y;
	while (iter)
	{
		curr = iter->content;
		if (curr->y < min)
			min = curr->y;
		if (curr->y > max)
			max = curr->y;
		iter = iter->next;
	}
	obj->coor_range->y_min = min;
	obj->coor_range->y_max = max;
}

void		set_coor_range(t_object **target)
{
	t_object *obj;

	obj = *target;
	obj->coor_range = (t_minmax *)malloc(sizeof(t_minmax));
	if (obj->coor_range == NULL)
		error(6);
	obj->coor_range->x_min = 0;
	obj->coor_range->x_max = obj->x_count - 1;
	obj->coor_range->z_min = 0;
	obj->coor_range->z_max = obj->z_count - 1;
	get_y_range(obj);
}
