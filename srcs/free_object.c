/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_object.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 17:20:24 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/19 10:41:37 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	free_win(t_win **target)
{
	t_win *win;

	win = *target;
	free(win->name);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	free(win->mlx_ptr);
	free(win);
	*target = NULL;
}

void			free_img(t_img **target, void *mlx_ptr)
{
	t_img	*img;

	img = *target;
	mlx_destroy_image(mlx_ptr, img->img_ptr);
	free(*target);
	*target = NULL;
}

void			free_minmax(t_minmax **target)
{
	t_minmax *coor_range;

	coor_range = *target;
	coor_range->x_min = 0;
	coor_range->x_max = 0;
	coor_range->y_min = 0;
	coor_range->y_max = 0;
	coor_range->z_min = 0;
	coor_range->z_max = 0;
	free(coor_range);
	*target = NULL;
}

static	void	free_all_vectors(t_object *obj)
{
	if (obj->input != NULL)
		free_vectors(&(obj->input), 1);
	if (obj->centre != NULL)
		free_vectors(&(obj->centre), 1);
	if (obj->scale != NULL)
		free_vectors(&(obj->scale), 1);
	if (obj->z_grid != NULL)
		free_vectors(&(obj->z_grid), 2);
	if (obj->x_grid != NULL)
		free_vectors(&(obj->x_grid), 2);
}

void			free_object(t_object **target)
{
	t_object *obj;

	obj = *target;
	if (obj->img != NULL)
		free_img(&(obj->img), obj->win->mlx_ptr);
	if (obj->win != NULL)
		free_win(&(obj->win));
	if (obj->coor_range != NULL)
		free_minmax(&(obj->coor_range));
	free_all_vectors(*target);
	if (obj->left != NULL)
		free(obj->left);
	if (obj->right != NULL)
		free(obj->right);
	if (obj->rotation != NULL)
		free(obj->rotation);
	free(obj);
	*target = NULL;
}
