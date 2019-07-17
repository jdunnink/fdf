/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scale_vectors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 12:15:04 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/17 11:48:50 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	scale_vectors() is used to scale objects to the middle of the img.
*/

static	void	vec_mult(t_vec **curr, int factor)
{
	t_vec *vector;

	vector = *curr;
	vector->x *= factor;
	vector->y *= factor;
	vector->z *= factor;
}

static	void	move(t_vec *curr, t_object *obj, unsigned width_os, unsigned height_os)
{
	curr->x += width_os;
	curr->y += height_os;
	curr->z += (width_os + height_os) / 2;
}

static	void	scale(t_vec *curr, unsigned total_vectors, unsigned height_os)
{
	if (total_vectors <= 5000)
		vec_mult(&curr, 25);
	else if (total_vectors <= 25000)
		vec_mult(&curr, 6);
	else if (total_vectors <= 50000)
		vec_mult(&curr, 3);
}

void			scale_vectors(t_object *obj)
{
	unsigned	height;
	unsigned	width;
	t_list		*iter;
	t_vec		*curr;

	height = (obj->img->height / 2);
	width = (obj->img->width / 2);
	iter = obj->scale;
	while (iter)
	{
		curr = iter->content;
		scale(curr, obj->total_vectors, height);
		move(curr, obj, width, height);
		iter = iter->next;
	}
}

