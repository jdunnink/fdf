/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_vectors.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 17:30:27 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:25:27 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_vectors(t_list **vectors, int mode)
{
	t_list	*iter;
	t_list	*trail;
	t_vec	*curr;

	iter = *vectors;
	trail = *vectors;
	while (iter)
	{
		curr = iter->content;
		if (mode == 1)
			free(curr);
		iter = iter->next;
		free(trail);
		trail = iter;
	}
	*vectors = NULL;
}
