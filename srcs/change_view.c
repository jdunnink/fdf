/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_view.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/19 11:34:16 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/19 12:27:12 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	flip_x(t_object *object, t_matrix *trix)
{
	t_list	*iter;
	t_vec	*vector;
	float	cosine;
	float	neg_sine;
	float	tmp;

	cosine = trix->cosine;
	neg_sine = trix->neg_sine;
	iter = object->centre;
	while (iter)
	{
		vector = iter->content;
		tmp = (vector->y * cosine) + (vector->z * trix->sine);
		vector->z = (vector->y * neg_sine) + (vector->z * cosine);
		vector->y = tmp;
		iter = iter->next;
	}
}

static	void	flip_y(t_object *object, t_matrix *trix)
{
	t_list	*iter;
	t_vec	*vector;
	float	cosine;
	float	neg_sine;
	float	tmp;

	cosine = trix->cosine;
	neg_sine = trix->neg_sine;
	iter = object->centre;
	while (iter)
	{
		vector = iter->content;
		tmp = (vector->x * cosine) + (vector->z * neg_sine);
		vector->z = (vector->x * trix->sine) + (vector->z * cosine);
		vector->x = tmp;
		iter = iter->next;
	}
}

static	void	flip_z(t_object *object, t_matrix *trix)
{
	t_list	*iter;
	t_vec	*vector;
	float	cosine;
	float	neg_sine;
	float	tmp;

	cosine = trix->cosine;
	neg_sine = trix->neg_sine;
	iter = object->centre;
	while (iter)
	{
		vector = iter->content;
		tmp = (vector->x * cosine) + (vector->y * trix->sine);
		vector->y = (vector->x * neg_sine) + (vector->y * cosine);
		vector->x = tmp;
		iter = iter->next;
	}
}

void			init_var(t_matrix **x, t_matrix **y, t_matrix **z, t_object *o)
{
	*x = NULL;
	*y = NULL;
	*z = NULL;
	free_img(&(o->img), o->win->mlx_ptr);
	set_vectors(o->centre, o->input);
	update_coor_range(o->centre, o->coor_range);
	center_vectors(o->centre, o->coor_range);
}

void			change_view(t_object *obj, float x, float y, float z)
{
	t_matrix	*x_trix;
	t_matrix	*y_trix;
	t_matrix	*z_trix;

	init_var(&x_trix, &y_trix, &z_trix, obj);
	if ((int)x != 0)
	{
		x_trix = get_matrix(x);
		flip_x(obj, x_trix);
		free(x_trix);
	}
	if ((int)y != 0)
	{
		y_trix = get_matrix(y);
		flip_y(obj, y_trix);
		free(y_trix);
	}
	if ((int)z != 0)
	{
		z_trix = get_matrix(z);
		flip_z(obj, z_trix);
		free(z_trix);
	}
	dump_image(obj);
}
