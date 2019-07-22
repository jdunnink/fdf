/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 15:51:28 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/19 09:37:52 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(int error_code)
{
	if (error_code == 1)
		ft_putendl("No input file found --> usage ./fdf <input_file>");
	else if (error_code == 2)
		ft_putendl("Could not allocate memory for new object.");
	else if (error_code == 3)
		ft_putendl("Could not open input_file.");
	else if (error_code == 4)
		ft_putendl("Encountered invalid number notation in input file.");
	else if (error_code == 5)
		ft_putendl("Could not allocate memory for new vector.");
	else if (error_code == 6)
		ft_putendl("Could not allocate memory for new coor_range struct.");
	else if (error_code == 7)
		ft_putendl("Could not read input_file.");
	exit(0);
}
