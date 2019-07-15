/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_colors.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 10:22:39 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/07/04 10:24:38 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	add_colors takes a list of vectors and based on their respective height,
**	assigns them a color. For reference, colors are defined in fdf.h. Currently,
**	vectors get assigned one of six colors, but this can be expanded.
**	When drawing lines between two vectors, the function get_color() calculates
**	a linear gradient.
*/

static	int	set_color(int y, int range)
{
	float	percentage;

	if (y < 0)
		y *= -1;
	if (range == 0)
		return (COLOR_JAFFA);
	percentage = ((y * 100) / range);
	if (percentage < 20)
		return (COLOR_DISCO);
	else if (percentage < 40)
		return (COLOR_BRICK_RED);
	else if (percentage < 60)
		return (COLOR_FLAMINGO);
	else if (percentage < 80)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}

void		add_colors(t_list *vectors, t_minmax *coor_range)
{
	t_list	*iter;
	t_vec	*curr;
	int		range;

	range = coor_range->y_max - coor_range->y_min;
	iter = vectors;
	while (iter)
	{
		curr = iter->content;
		curr->color = set_color(curr->y, range);
		iter = iter->next;
	}
}