/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 15:12:07 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/19 12:44:57 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_object *obj;

	if (argc < 2)
		error(1);
	read_input(argv[1], &obj);
	init_win(1500, 1200, (&(obj->win)), "FDF");
	init_img((&(obj->img)), obj->win, obj->win->width, obj->win->height);
	obj->centre = ft_lstmap(obj->input, &ft_lstcpy_elem);
	center_vectors(obj->centre, obj->coor_range);
	obj->scale = ft_lstmap(obj->centre, &ft_lstcpy_elem);
	scale_vectors(obj);
	update_coor_range(obj->scale, obj->coor_range);
	set_x_grid(obj);
	set_z_grid(obj);
	draw_object(obj);
	mlx_hook(obj->win->win_ptr, 3, 1, &key_release, obj);
	mlx_hook(obj->win->win_ptr, 2, 1, &key_press, obj);
	mlx_loop(obj->win->mlx_ptr);
	return (0);
}
