/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_win.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 18:09:40 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/07/04 11:43:13 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	initiate a new window struct, dimensions are variable
**	and can be set using x and y.
*/

void	init_win(int x, int y, t_win **win, char *name)
{
	*win = (t_win*)malloc(sizeof(t_win));
	(*win)->mlx_ptr = mlx_init();
	(*win)->win_ptr = mlx_new_window((*win)->mlx_ptr, x, y, name);
	(*win)->height = y;
	(*win)->width = x;
	(*win)->depth = y;
	(*win)->name = ft_strdup(name);
}