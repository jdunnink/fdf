/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_vector.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 15:45:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/19 10:25:49 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	push_vector(int x, int y, int z, t_object *obj)
{
	t_vec *vector;

	vector = (t_vec*)malloc(sizeof(t_vec));
	if (!vector)
		error(5);
	vector->x = (float)x;
	vector->y = (float)y * -1;
	vector->z = (float)z;
	vector->x_br = 0;
	vector->z_br = 0;
	vector->color = 0;
	ft_lstappend(&(obj->input), vector, sizeof(t_vec));
}
