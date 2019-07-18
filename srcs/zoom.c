/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zoom.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 12:18:38 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:35:25 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	zoom() is used to move an object closer or further away. This is done
**	by multiplying vector components with a scaling factor. (zoom)
*/

static	void	amp_vectors(t_list *vectors, float zoom)
{
	t_list	*iter;
	t_vec	*curr;

	iter = vectors;
	while (iter)
	{
		curr = iter->content;
		curr->x *= zoom;
		curr->y *= zoom;
		curr->z *= zoom;
		iter = iter->next;
	}
}

void			zoom(t_object *obj, int keycode, float z_out, float z_in)
{
	float zoom;

	free_img(&(obj->img), obj->win->mlx_ptr);
	if (keycode == 6)
		zoom = z_out;
	else
		zoom = z_in;
	amp_vectors(obj->centre, zoom);
	set_vectors(obj->scale, obj->centre);
	init_img(&(obj->img), obj->win, obj->win->width, obj->win->height);
	scale_vectors(obj);
	draw_object(obj);
	mlx_put_image_to_window(obj->win->mlx_ptr,
							obj->win->win_ptr,
							obj->img->img_ptr, 0, 0);
}
