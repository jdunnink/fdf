/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 15:45:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:38:50 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	push_vector(int x, int y, int z, t_object *obj)
{
	t_vec *vector;

	vector = (t_vec*)malloc(sizeof(t_vec));
	if (!vector)
		error(5);
	vector->x = (float)x;
	vector->y = (float)y * -1;
	vector->z = (float)z;
	vector->x_br = 0;
	vector->z_br = 0;
	vector->color = 0;
	ft_lstappend(&(obj->input), vector, sizeof(t_vec));
}

static	void	process_line(char *l, unsigned l_nb, t_object *obj)
{
	char			**nums;
	unsigned int	i;
	t_vec			*curr;

	nums = ft_strsplit(l, ' ');
	i = 0;
	while (nums[i] != NULL)
	{
		if (is_valid_nbr(nums[i]) == 1)
			push_vector(i, ft_atoi(nums[i]), l_nb, obj);
		else if (is_alt_nbr(nums[i]) == 1)
			push_vector(i, extract_nbr(nums[i]), l_nb, obj);
		else
			error(4);
		free(nums[i]);
		i++;
	}
	if (obj->x_count == 0)
		obj->x_count = i;
	free(nums);
}

static	int		get_vectors(char *input_file, t_object *obj)
{
	int				fd;
	char			*line;
	unsigned int	i;
	int				stat;
	int				first_line;

	fd = open(input_file, 0);
	if (fd == -1)
		error(3);
	i = 0;
	stat = 1;
	line = NULL;
	first_line = 0;
	while (stat != -1 && stat != 0)
	{
		stat = get_next_line(fd, &line);
		if (first_line == 0)
		{
			first_line = 1;
			if (ft_strlen(line) > 3000)
			{
				close(fd);
				free(line);
				line = NULL;
				return (0);
			}
		}
		if (line)
		{
			process_line(line, i, obj);
			free(line);
			line = NULL;
		}
		i++;
	}
	if (obj->z_count == 0)
		obj->z_count = i - 1;
	close(fd);
	return (1);
}

void			read_input(char *input_file, t_object **obj)
{
	if (init_object(obj) == 0)
		error(2);
	if (get_vectors(input_file, *obj) == 0)
		alt_get_vectors(input_file, *obj);
	(*obj)->total_vectors = (*obj)->x_count * (*obj)->z_count;
	set_coor_range(obj);
	add_colors((*obj)->input, (*obj)->coor_range);
}
