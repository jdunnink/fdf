/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_release.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 18:03:32 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/19 11:58:38 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Given a keycode, key_release handles program termination when using
**	the 'esc' key.
*/

int	key_release(int keycode, t_object *obj)
{
	if (keycode == 53)
	{
		free_object(&obj);
		exit(0);
	}
	else if (keycode == 17)
		change_view(obj, 90, 0, 0);
	else if (keycode == 15)
		reset(obj);
	else if (keycode == 34)
		change_view(obj, 45, 45, -28.57);
	return (0);
}
