/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/18 17:32:39 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/19 12:25:13 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			reset(t_object *obj)
{
	free_img(&(obj->img), obj->win->mlx_ptr);
	set_vectors(obj->centre, obj->input);
	update_coor_range(obj->centre, obj->coor_range);
	center_vectors(obj->centre, obj->coor_range);
	dump_image(obj);
}
