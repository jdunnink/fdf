/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_object.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 09:22:21 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:29:13 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_object(t_object *obj)
{
	draw_grid(obj->img, obj->x_grid, 'x');
	draw_grid(obj->img, obj->z_grid, 'z');
	mlx_put_image_to_window(obj->win->mlx_ptr,
								obj->win->win_ptr, obj->img->img_ptr, 0, 0);
	add_interface(obj);
}
