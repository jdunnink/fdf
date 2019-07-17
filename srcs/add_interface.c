/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_interface.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 10:24:58 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/17 09:49:44 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	add_interface adds a rudimentary interface to the window pointed to by
**	win_ptr, using mlx_string_put.
*/

void	add_interface(t_object *obj)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = obj->win->mlx_ptr;
	win_ptr = obj->win->win_ptr;
	mlx_string_put(mlx_ptr, win_ptr, 50, 50, TEXT_COLOR, "Rotate x: W, S");
	mlx_string_put(mlx_ptr, win_ptr, 50, 70, TEXT_COLOR, "Rotate y: A, D");
	mlx_string_put(mlx_ptr, win_ptr, 50, 90, TEXT_COLOR, "Rotate z: Q, E");
	mlx_string_put(mlx_ptr, win_ptr, 50, 110, TEXT_COLOR, "Zoom In/Out: Z, X");
	mlx_string_put(mlx_ptr, win_ptr, 50, 130, TEXT_COLOR, "Isometric view: I");
	mlx_string_put(mlx_ptr, win_ptr, 50, 150, TEXT_COLOR, "Parallel view: P");
}