/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_grid.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 09:05:41 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/19 10:46:56 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_grid(t_img *img, t_list *grid, char type)
{
	t_list		*iter;
	t_vec		*curr;
	t_vec		*next;
	t_point		sign;

	iter = grid;
	while (iter)
	{
		curr = iter->content;
		if (iter->next == NULL)
			break ;
		next = (iter->next)->content;
		if (type == 'z')
		{
			if (curr->z_br == 0)
				draw_line(img, *curr, *next, sign);
		}
		else if (type == 'x')
		{
			if (curr->x_br == 0)
				draw_line(img, *curr, *next, sign);
		}
		iter = iter->next;
	}
}
