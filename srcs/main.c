/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 15:12:07 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/07/15 15:12:09 by jdunnink      ########   odam.nl         */
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
//	print_vectors(obj->input);

	//----------------------------------------------------STAGE 2--------------------------------------------------------------
	
	printf("initiating window struct...\n");
	init_win(1500, 1200, (&(obj->win)), "FDF");

	printf("initiating img struct...\n");
	init_img((&(obj->img)), obj->win, obj->win->width, obj->win->height);

//	printf("Copying vector list...\n");
//	obj->centre = ft_lstmap(obj->input, &copy_vector);

	printf("printing centre vector list..\n");	
	print_vectors(obj->centre);

	printf("checking object status..\n");
	print_obj_stat(&obj);
	printf("freeing object..\n");
	free_object(&obj);
	printf("exiting program...\n");
	return (0);
}