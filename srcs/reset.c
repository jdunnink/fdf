/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/18 17:32:39 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:25:10 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			reset(t_object *obj)
{
	free_img(&(obj->img), obj->win->mlx_ptr);
	set_vectors(obj->centre, obj->input);
	update_coor_range(obj->centre, obj->coor_range);
	center_vectors(obj->centre, obj->coor_range);
	set_vectors(obj->scale, obj->centre);
	init_img(&(obj->img), obj->win, obj->win->width, obj->win->height);
	scale_vectors(obj);
	draw_object(obj);
	mlx_put_image_to_window(obj->win->mlx_ptr,
							obj->win->win_ptr,
							obj->img->img_ptr, 0, 0);
	add_interface(obj);
}
