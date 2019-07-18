/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_obj_stat.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 18:55:29 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:24:25 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_obj_stat(t_object **target)
{
	t_object *obj;

	obj = *target;
	printf("\nOBJECT STATUS: \n");
	if (obj == NULL)
	{
		printf("	object does not exist!\n");
		return ;
	}
	printf("	win : %p\n", obj->win);
	if (obj->win != NULL)
	{
		printf("		win_ptr: %p\n", obj->win->win_ptr);
		printf("		mlx_ptr: %p\n", obj->win->mlx_ptr);
		printf("		width:	%lu\n", obj->win->width);
		printf("		height:	%lu\n", obj->win->height);
		printf("		depth:	%lu\n", obj->win->depth);
		printf("		name:	%s\n", obj->win->name);
	}
	printf("	img : %p\n", obj->img);
	if (obj->img != NULL)
	{
		printf("		img_ptr: %p\n", obj->img->img_ptr);
		printf("		img_height: %i\n", obj->img->height);
		printf("		img_width: %i\n", obj->img->width);
		printf("		pixels: %p\n", obj->img->pixels);
		printf("		bpp: %i\n", obj->img->bpp);
		printf("		size_line: %i\n", obj->img->size_line);
		printf("		endian: %i\n", obj->img->endian);
	}
	printf("	input : %p\n", obj->input);
	printf("	centre : %p\n", obj->centre);
	printf("	scale : %p\n", obj->scale);
	printf("	coor_range : %p\n", obj->coor_range);
	if (obj->coor_range != NULL)
	{
		printf("		CR->xmin: %.f\n", obj->coor_range->x_min);
		printf("		CR->xmax: %.f\n", obj->coor_range->x_max);
		printf("		CR->ymin: %.f\n", obj->coor_range->y_min);
		printf("		CR->ymax: %.f\n", obj->coor_range->y_max);
		printf("		CR->zmin: %.f\n", obj->coor_range->z_min);
		printf("		CR->zmax: %.f\n", obj->coor_range->z_max);
	}
	printf("	z_grid : %p\n", obj->z_grid);
	printf("	x_grid : %p\n", obj->x_grid);
	printf("	x_count : %u\n", obj->x_count);
	printf("	z_count : %u\n", obj->z_count);
	printf("	total_vectors : %u\n", obj->total_vectors);
	printf("	left matrix: %p\n", obj->left);
	if (obj->left != NULL)
	{
		printf("		constant: %f\n", obj->left->constant);
		printf("		cosine: %f\n", obj->left->cosine);
		printf("		sine: %f\n", obj->left->sine);
		printf("		neg_sine: %f\n", obj->left->neg_sine);
	}
	printf("	right matrix: %p\n", obj->right);
	if (obj->right != NULL)
	{
		printf("		constant: %f\n", obj->left->constant);
		printf("		cosine: %f\n", obj->left->cosine);
		printf("		sine: %f\n", obj->left->sine);
		printf("		neg_sine: %f\n", obj->left->neg_sine);
	}
	printf("	active matrix:	%p\n", obj->rotation);
	if (obj->rotation != NULL)
	{
		printf("		constant: %f\n", obj->left->constant);
		printf("		cosine: %f\n", obj->left->cosine);
		printf("		sine: %f\n", obj->left->sine);
		printf("		neg_sine: %f\n", obj->left->neg_sine);
	}
	ft_putchar('\n');
}
