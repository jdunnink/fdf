/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_object.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 16:19:09 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/07/15 16:19:10 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		init_object(t_object **obj)
{
	*obj = (t_object*)malloc(sizeof(t_object));
	if (!(*obj))
		return (0);
	(*obj)->win = NULL;
	(*obj)->img = NULL;
	(*obj)->input = NULL;
	(*obj)->centre = NULL;
	(*obj)->scale = NULL;
	(*obj)->coor_range = NULL;
	(*obj)->z_grid = NULL;
	(*obj)->x_grid = NULL;
	(*obj)->x_count = 0;
	(*obj)->z_count = 0;
	(*obj)->total_vectors = 0;
	return (1);
}	