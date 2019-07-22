/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_coor_range.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 13:55:49 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:35:45 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_x_range(t_list *vectors, t_minmax *coor_range)
{
	t_list	*iter;
	t_vec	*curr;
	float	min;
	float	max;

	iter = vectors;
	curr = iter->content;
	min = curr->x;
	max = curr->x;
	while (iter)
	{
		curr = iter->content;
		if (curr->x < min)
			min = curr->x;
		if (curr->x > max)
			max = curr->x;
		iter = iter->next;
	}
	coor_range->x_min = min;
	coor_range->x_max = max;
}

static void	get_y_range(t_list *vectors, t_minmax *coor_range)
{
	t_list	*iter;
	t_vec	*curr;
	float	min;
	float	max;

	iter = vectors;
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
	coor_range->y_min = min;
	coor_range->y_max = max;
}

static void	get_z_range(t_list *vectors, t_minmax *coor_range)
{
	t_list	*iter;
	t_vec	*curr;
	float	min;
	float	max;

	iter = vectors;
	curr = iter->content;
	min = curr->z;
	max = curr->z;
	while (iter)
	{
		curr = iter->content;
		if (curr->z < min)
			min = curr->z;
		if (curr->z > max)
			max = curr->z;
		iter = iter->next;
	}
	coor_range->z_min = min;
	coor_range->z_max = max;
}

void		update_coor_range(t_list *vectors, t_minmax *coor_range)
{
	get_x_range(vectors, coor_range);
	get_y_range(vectors, coor_range);
	get_z_range(vectors, coor_range);
}
