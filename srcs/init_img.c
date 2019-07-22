/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_img.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 10:55:48 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:25:22 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	initializes the image_ptr, located in the window struct.
**	image characteristics are stored in the img struct, using get_data_addr.
*/

void	init_img(t_img **img, t_win *window, int width, int height)
{
	char	*output;
	int		bpp;
	int		size_line;
	int		endian;

	*img = (t_img *)malloc(sizeof(t_img));
	(*img)->height = height;
	(*img)->width = width;
	(*img)->img_ptr = mlx_new_image(window->mlx_ptr,
									(*img)->width, (*img)->height);
	if ((*img)->img_ptr == NULL)
	{
		ft_putendl("could not allocate pixmap in memory!");
		exit(0);
	}
	(*img)->pixels = mlx_get_data_addr((*img)->img_ptr,
										&bpp, &size_line, &endian);
	(*img)->bpp = bpp;
	(*img)->size_line = size_line;
	(*img)->endian = endian;
}
