/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_grid.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 09:05:41 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:30:55 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	check_line(t_vec start, t_vec end, unsigned *lines, t_img *img)
{
	if (start.x < 0 || start.y < 0 || end.x < 0 || end.y < 0)
		return (0);
	if (start.x > img->width || end.x > img->width)
		return (0);
	if (start.y > img->height || end.y > img->height)
		return (0);
	if (start.x == end.x && start.y == end.y)
		return (0);
	(*lines)++;
	return (1);
}

void		draw_grid(t_img *img, t_list *grid, char type)
{
	t_list		*iter;
	t_vec		*curr;
	t_vec		*next;
	t_point		sign;
	unsigned	lines;

	iter = grid;
	lines = 0;
	while (iter)
	{
		curr = iter->content;
		if (iter->next == NULL)
			break ;
		next = (iter->next)->content;
		if (type == 'z')
		{
			if (curr->z_br == 0)
				if (check_line(*curr, *next, &lines, img) == 1)
					draw_line(img, *curr, *next, sign);
		}
		else if (type == 'x')
		{
			if (curr->x_br == 0)
				if (check_line(*curr, *next, &lines, img) == 1)
					draw_line(img, *curr, *next, sign);
		}
		iter = iter->next;
	}
}
