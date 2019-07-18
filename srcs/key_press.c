/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_press.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 18:03:32 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:25:17 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Given a keycode, key_press handles events for rotation, zooming and
**	perspective changes.
*/

static	t_matrix	*copy_matrix(t_matrix *trix)
{
	t_matrix *dest;

	dest = (t_matrix *)malloc(sizeof(t_matrix));
	dest->constant = trix->constant;
	dest->cosine = trix->cosine;
	dest->sine = trix->sine;
	dest->neg_sine = trix->neg_sine;
	return (dest);
}

static	void		handle_rotation(int *change, int keycode, t_object *obj)
{
	if (keycode == 13)
		rotate(obj, 'x', 1);
	else if (keycode == 1)
		rotate(obj, 'x', 1);
	else if (keycode == 0)
		rotate(obj, 'y', 1);
	else if (keycode == 2)
		rotate(obj, 'y', 1);
	else if (keycode == 12)
		rotate(obj, 'z', 1);
	else if (keycode == 14)
		rotate(obj, 'z', 1);
	*change = 1;
}

int					key_press(int keycode, t_object *obj)
{
	int change;

	change = 0;
	if (keycode == 13 || keycode == 0 || keycode == 12)
	{
		free(obj->rotation);
		obj->rotation = copy_matrix(obj->right);
	}
	else if (keycode == 1 || keycode == 2 || keycode == 14)
	{
		free(obj->rotation);
		obj->rotation = copy_matrix(obj->left);
	}
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2 ||
		keycode == 12 || keycode == 14)
		handle_rotation(&change, keycode, obj);
	else if (keycode == 6 || keycode == 7)
	{
		zoom(obj, keycode, 0.95, 1.05);
		change = 1;
	}
	if (change == 1)
		add_interface(obj);
	return (0);
}
