/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   center_vectors.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 10:29:01 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/17 11:43:07 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	center_vectors takes a list of vectors and centers them around a central
**	zero point. For example, a list where x = {1, 2, 3, 4, 5} becomes
**	x = (-2, -1, 0, 1, 2).
*/

static	void	center(t_vec *vector, char axis, float nb)
{
	if (axis == 'x')
		(vector->x) -= nb;
	else if (axis == 'y')
		(vector->y) += nb;
	else if (axis == 'z')
		(vector->z) -= nb;
}

static	void	center_x(t_list *vectors, float x_min, float x_max)
{
	t_list	*iter;
	t_vec	*curr;
	float	offset;

	offset = (x_max - x_min) / 2;
	printf("	center x offset: %.2f\n", offset);
	if (offset == x_max && offset == (x_min * -1))
	{
		printf("		no centering required!\n");
		return ;
	}
	iter = vectors;
	while (iter)
	{
		curr = iter->content;
		center(curr, 'x', offset);
		iter = iter->next;
	}
}

static	void	center_y(t_list *vectors, float y_min, float y_max)
{
	t_list	*iter;
	t_vec	*curr;
	float	offset;
	
	offset = (y_max - y_min) / 2;
	printf("	center y offset: %.2f\n", offset);
	if (offset == y_max && offset == (y_min * -1))
	{
		printf("		no centering required!\n");
		return ;
	}
	iter = vectors;
	while (iter)
	{
		curr = iter->content;
		center(curr, 'y', offset);
		iter = iter->next;
	}
}

static	void	center_z(t_list *vectors, float z_min, float z_max)
{
	t_list	*iter;
	t_vec	*curr;
	float	offset;

	offset = (z_max - z_min) / 2;
	printf("	center z offset: %.2f\n", offset);
	if (offset == z_max && offset == (z_min * -1))
	{
		printf("		no centering required!\n");
		return ;
	}
	iter = vectors;
	while (iter)
	{
		curr = iter->content;
		center(curr, 'z', offset);
		iter = iter->next;
	}
}

void			center_vectors(t_list *vectors, t_minmax *coor_range)
{
	center_x(vectors, coor_range->x_min, coor_range->x_max);
	center_y(vectors, coor_range->y_min, coor_range->y_max);
	center_z(vectors, coor_range->z_min, coor_range->z_max);
}
