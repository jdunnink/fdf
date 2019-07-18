/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_object.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 16:19:09 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:26:35 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*get_matrix(float angle)
{
	t_matrix *trix;

	trix = (t_matrix *)malloc(sizeof(t_matrix));
	trix->constant = 1;
	trix->cosine = cos(0.0174532925 * angle);
	trix->sine = sin(0.0174532925 * angle);
	trix->neg_sine = -sin(0.0174532925 * angle);
	return (trix);
}

int			init_object(t_object **obj)
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
	(*obj)->left = get_matrix(-3.00);
	(*obj)->right = get_matrix(3.00);
	(*obj)->rotation = NULL;
	return (1);
}
