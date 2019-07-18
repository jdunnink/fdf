/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_pixel_put.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 10:54:52 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:25:23 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Given a 2d position represented by x,y, ing_pixel_put() sets the color value
**	of the corresponding pixel at img_ptr to the color passed as argument.
**	For correct use, the bbp and the size_line variables need to match the
**	the img that is being used. For reference, check mlx_img man pages.
*/

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	int	pos;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		pos = (x * img->bpp / 8) + (y * img->size_line);
		img->pixels[pos] = color % 256;
		img->pixels[pos + 1] = (color >> 8) % 256;
		img->pixels[pos + 2] = (color >> 16) % 256;
	}
}
