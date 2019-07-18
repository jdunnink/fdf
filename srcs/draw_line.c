/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/12 12:46:29 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:25:30 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	draw_line() is the main linedrawing algorithm in this program.
**	given two points in 3D space, draw_line draws a straight line,
**	between these two points, using repeated calls to img_pixel_put.
**	Primarily based on Bresenham's line drawing algorithm -->
**	https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
*/

void	init_points(t_point *begin, t_point *ending, t_vec start, t_vec end)
{
	begin->x = start.x;
	begin->y = start.y;
	begin->color = start.color;
	ending->x = end.x;
	ending->y = end.y;
	ending->color = end.color;
}

void	init_delta(t_point *delta, t_vec start, t_vec end)
{
	delta->x = ft_abs((int)end.x - (int)start.x);
	delta->y = ft_abs((int)end.y - (int)start.y);
}

void	init_sign(t_point *sign, t_vec start, t_vec end)
{
	if ((int)start.x < (int)end.x)
		sign->x = 1;
	else
		sign->x = -1;
	if ((int)start.y < (int)end.y)
		sign->y = 1;
	else
		sign->y = -1;
}

void	interpolate(int *error, t_point *delta, t_point *sign, t_point *curr)
{
	error[1] = error[0] * 2;
	if (error[1] > -delta->y)
	{
		error[0] -= delta->y;
		curr->x += sign->x;
	}
	if (error[1] < delta->x)
	{
		error[0] += delta->x;
		curr->y += sign->y;
	}
}

void	draw_line(t_img *img, t_vec start, t_vec end, t_point sign)
{
	t_point	delta;
	t_point	curr;
	t_point begin;
	t_point ending;
	int		error[2];

	init_points(&begin, &ending, start, end);
	init_delta(&delta, start, end);
	init_sign(&sign, start, end);
	error[0] = delta.x - delta.y;
	curr.x = (int)start.x;
	curr.y = (int)start.y;
	while (curr.x != (int)end.x || curr.y != (int)end.y)
	{
		img_pixel_put(img, curr.x,
						curr.y, get_color(curr, begin, ending, delta));
		interpolate(&(error[0]), &delta, &sign, &curr);
	}
}
