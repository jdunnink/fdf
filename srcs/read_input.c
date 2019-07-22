/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 15:45:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/19 09:55:15 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			read_input(char *input_file, t_object **obj)
{
	if (init_object(obj) == 0)
		error(2);
	if (get_vectors(input_file, *obj) == 0)
		alt_get_vectors(input_file, *obj);
	(*obj)->total_vectors = (*obj)->x_count * (*obj)->z_count;
	set_coor_range(obj);
	add_colors((*obj)->input, (*obj)->coor_range);
}
