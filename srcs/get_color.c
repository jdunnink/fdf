/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 10:49:09 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/17 09:29:59 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	get_color() is used in draw_line() to achieve a linear gradient in the
**	line. Given two points in 2d space and their colors (start, end), the curr
**	position is used to interpolate the RGB values of the color needed.
**	As a result, color of the target pixel will be between startcolor and
**	endcolor, in direct relationship to the relative curr position.
*/

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_point curr, t_point start, t_point end, t_point d)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (curr.color == end.color)
		return (curr.color);
	if (d.x > d.y)
		percentage = percent(start.x, end.x, curr.x);
	else
		percentage = percent(start.y, end.y, curr.y);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) &
					0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) &
					0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}