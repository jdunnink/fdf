/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view_top.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/18 16:52:07 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:25:02 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	flip(t_object *object, t_matrix *trix)
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

void			view_top(t_object *obj)
{
	t_matrix	*change;

	free_img(&(obj->img), obj->win->mlx_ptr);
	change = get_matrix(90);
	set_vectors(obj->centre, obj->input);
	update_coor_range(obj->centre, obj->coor_range);
	center_vectors(obj->centre, obj->coor_range);
	flip(obj, change);
	free(change);
	set_vectors(obj->scale, obj->centre);
	init_img(&(obj->img), obj->win, obj->win->width, obj->win->height);
	scale_vectors(obj);
	draw_object(obj);
	mlx_put_image_to_window(obj->win->mlx_ptr,
							obj->win->win_ptr,
							obj->img->img_ptr, 0, 0);
	add_interface(obj);
}
