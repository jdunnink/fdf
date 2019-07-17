/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_vectors.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 19:10:51 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/17 19:13:54 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_vectors(t_list *dest, t_list *src)
{
	t_vec	*curr_dest;
	t_vec	*curr_src;

	while (src && dest)
	{
		curr_src = src->content;
		curr_dest = dest->content;
		curr_dest->x = curr_src->x;
		curr_dest->y = curr_src->y;
		curr_dest->z = curr_src->z;
		src = src->next;
		dest = dest->next;
	}
}