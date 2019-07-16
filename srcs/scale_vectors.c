/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scale_into_view.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 12:15:04 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/07/04 12:18:21 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	scale_into_view() is used to scale objects to the middle of the img.
*/

static	void	zoom_vectors(t_list *vectors)
{
	t_list	*iter;
	t_vec	*curr;

	iter = vectors;
	while (iter)
	{
		curr = iter->content;
		curr->x *= 30.50;
		curr->y *= 24.50;
		curr->z *= 30.50;
		iter = iter->next;
	}
}

static	void	move_vectors(t_list *vectors)
{
	t_list	*iter;
	t_vec	*curr;

	iter = vectors;
	while (iter)
	{
		curr = iter->content;
		curr->x += 25;
		curr->y += 25;
		curr->z += 25;
		iter = iter->next;
	}
}

void			scale_vectors(t_list *vectors)
{
	move_vectors(vectors);
	zoom_vectors(vectors);
}