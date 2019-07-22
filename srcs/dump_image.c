/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dump_image.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/19 12:06:26 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/19 12:26:08 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dump_image(t_object *obj)
{
	set_vectors(obj->scale, obj->centre);
	init_img(&(obj->img), obj->win, obj->win->width, obj->win->height);
	scale_vectors(obj);
	draw_object(obj);
	mlx_put_image_to_window(obj->win->mlx_ptr,
							obj->win->win_ptr,
							obj->img->img_ptr, 0, 0);
	add_interface(obj);
}
