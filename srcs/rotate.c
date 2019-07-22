/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 18:34:51 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:25:09 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	rotate() is used to apply rotation to a centered vector list. Mathematical
**	constants are retrieved from the matrix in the object struct and used
**	to calculate rotation around a given axis. Only works on vectors lists
**	that are normalized around zero.
*/

static	void	rotate_x(t_object *object)
{
	t_list	*iter;
	t_vec	*vector;
	float	cosine;
	float	neg_sine;
	float	tmp;

	cosine = object->rotation->cosine;
	neg_sine = object->rotation->neg_sine;
	iter = object->centre;
	while (iter)
	{
		vector = iter->content;
		tmp = (vector->y * cosine) + (vector->z * object->rotation->sine);
		vector->z = (vector->y * neg_sine) + (vector->z * cosine);
		vector->y = tmp;
		iter = iter->next;
	}
}

static	void	rotate_y(t_object *object)
{
	t_list	*iter;
	t_vec	*vector;
	float	cosine;
	float	neg_sine;
	float	tmp;

	cosine = object->rotation->cosine;
	neg_sine = object->rotation->neg_sine;
	iter = object->centre;
	while (iter)
	{
		vector = iter->content;
		tmp = (vector->x * cosine) + (vector->z * neg_sine);
		vector->z = (vector->x * object->rotation->sine) + (vector->z * cosine);
		vector->x = tmp;
		iter = iter->next;
	}
}

static	void	rotate_z(t_object *object)
{
	t_list	*iter;
	t_vec	*vector;
	float	cosine;
	float	neg_sine;
	float	tmp;

	cosine = object->rotation->cosine;
	neg_sine = object->rotation->neg_sine;
	iter = object->centre;
	while (iter)
	{
		vector = iter->content;
		tmp = (vector->x * cosine) + (vector->y * object->rotation->sine);
		vector->y = (vector->x * neg_sine) + (vector->y * cosine);
		vector->x = tmp;
		iter = iter->next;
	}
}

void			rotate(t_object *obj, char type, int render)
{
	free_img(&(obj->img), obj->win->mlx_ptr);
	if (type == 'x')
		rotate_x(obj);
	else if (type == 'y')
		rotate_y(obj);
	else if (type == 'z')
		rotate_z(obj);
	set_vectors(obj->scale, obj->centre);
	init_img(&(obj->img), obj->win, obj->win->width, obj->win->height);
	scale_vectors(obj);
	draw_object(obj);
	if (render == 1)
	{
		mlx_put_image_to_window(obj->win->mlx_ptr,
								obj->win->win_ptr,
								obj->img->img_ptr, 0, 0);
	}
}
