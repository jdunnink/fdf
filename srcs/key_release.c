/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_release.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 18:03:32 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/17 09:52:42 by jdunnink      ########   odam.nl         */
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
		printf("freeing object..\n");
		free_object(&obj);
		printf("exiting program...\n");
		exit(0);
	}
	return (0);
}