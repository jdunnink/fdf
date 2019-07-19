/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_line.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/12 12:46:29 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/19 12:29:20 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_line(t_img *img, t_vec start, t_vec end)
{
	if (start.x < (img->width / 4) * -1 || end.x < (img->width / 4) * -1)
		return (0);
	if (start.y < (img->height / 4) * -1 || end.y < (img->height / 4) * -1)
		return (0);
	if (start.x > img->width * 1.25 || end.x > img->width * 1.25)
		return (0);
	if (start.y > img->height * 1.25 || end.y > img->height * 1.25)
		return (0);
	return (1);
}
