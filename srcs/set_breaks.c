/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_breaks.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 20:36:54 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/17 20:44:30 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_breaks(t_list *grid, int type)
{
	t_list	*iter;
	t_vec	*curr;
	t_vec	*next;

	iter = grid;
	while (iter->next)
	{
		curr = iter->content;
		next = ((t_vec *)(iter->next)->content);
		if (type == 'x')
		{
			if (curr->z != next->z)
				curr->br = 1; 
		}
		else if (type == 'z')
		{
			if (curr->x != next->x)
				curr->br = 1;
		}
		iter = iter->next;
	}
}