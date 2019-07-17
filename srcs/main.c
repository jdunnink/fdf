/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 15:12:07 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/17 19:37:24 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_object *obj;

	if (argc < 2)
		error(1);

	printf("---------------------------PROGRAM START: FDF----------------------------------\n");

	//---------------------------------------------------STAGE 1---------------------------------------------------------------

	printf("reading input file..\n");
	read_input(argv[1], &obj);

//	printf("printing input vector list..\n");	
//	print_vectors(obj->input, 1);

	//----------------------------------------------------STAGE 2--------------------------------------------------------------
	
	printf("initiating window struct...\n");
	init_win(1500, 1200, (&(obj->win)), "FDF");

	printf("initiating img struct...\n");
	init_img((&(obj->img)), obj->win, obj->win->width, obj->win->height);

	printf("Copying input vector list to centre...\n");
	if (obj->total_vectors < 30000)
		obj->centre = ft_lstmap(obj->input, &copy_vector);
	else
		obj->centre = ft_lstcpy(obj->input);

	printf("Centering copied vector list....\n");
	center_vectors(obj->centre, obj->coor_range);

//	printf("printing centre vector list..\n");	
//	print_vectors(obj->centre, 1);

	printf("Copying centre vector list to scale...\n");
	if (obj->total_vectors < 30000)
		obj->scale = ft_lstmap(obj->centre, &copy_vector);
	else
		obj->scale = ft_lstcpy(obj->centre);

	printf("Scaling copied list into view....\n");
	scale_vectors(obj);

	printf("Updating coor_range....\n");
	update_coor_range(obj->scale, obj->coor_range);

	printf("Setting z_grid/x_grid list pointers...\n");
	set_x_grid(obj);
	set_z_grid(obj);

//	printf("printing scaled vector list..\n");	
//	print_vectors(obj->scale, 1);

	printf("checking object status..\n");
	print_obj_stat(&obj);

	//----------------------------------------------------STAGE 3--------------------------------------------------------------

	printf("drawing object in current img...\n");
	draw_object(obj);

	printf("setting input hooks and starting mlx_loop...\n");
	mlx_hook(obj->win->win_ptr, 3, 1, &key_release, obj);
	mlx_hook(obj->win->win_ptr, 2, 1, &key_press, obj);
	mlx_loop(obj->win->mlx_ptr);

	//----------------------------------------------------STAGE 4--------------------------------------------------------------

	return (0);
}