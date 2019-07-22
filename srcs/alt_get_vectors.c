/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alt_get_vectors.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 15:45:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/19 10:45:09 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	split_line(char ***nums, char *l, unsigned *i, unsigned *x)
{
	*nums = ft_strsplit(l, ' ');
	*i = 0;
	*x = 0;
}

static	void	process_line(char *l, unsigned l_nb, t_object *obj)
{
	char			**nums;
	unsigned int	i;
	unsigned int	x;
	t_vec			*curr;

	split_line(&nums, l, &i, &x);
	while (nums[i] != NULL)
	{
		if (i % 2 != 0)
		{
			if (is_valid_nbr(nums[i]) == 1)
				push_vector(x, ft_atoi(nums[i]), l_nb, obj);
			else if (is_alt_nbr(nums[i]) == 1)
				push_vector(x, extract_nbr(nums[i]), l_nb, obj);
			else
				error(4);
			x++;
		}
		free(nums[i]);
		i++;
	}
	if (obj->x_count == 0)
		obj->x_count = x;
	free(nums);
}

static	void	init_var(int *fd, unsigned *i, int *stat, char **input_file)
{
	*fd = open(*input_file, 0);
	if (*fd == -1)
		error(3);
	*i = 0;
	*stat = 1;
}

void			alt_get_vectors(char *input_file, t_object *obj)
{
	int				fd;
	char			*line;
	unsigned int	i;
	int				stat;

	init_var(&fd, &i, &stat, &input_file);
	line = NULL;
	while (stat != -1 && stat != 0)
	{
		stat = get_next_line(fd, &line);
		if (line)
		{
			if (i % 2 != 0)
			{
				process_line(line, obj->z_count, obj);
				(obj->z_count)++;
			}
			free(line);
			line = NULL;
		}
		i++;
	}
	close(fd);
}
