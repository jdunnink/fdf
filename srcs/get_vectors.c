/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_vectors.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 15:45:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/19 10:27:45 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static	int		check_size(int *fd, char **line, int *first)
{
	*first = 1;
	if (ft_strlen(*line) > 3000)
	{
		close(*fd);
		ft_strdel(line);
		return (0);
	}
	return (1);
}

static	void	init_var(int *fd, unsigned *i, int *stat, char **input_file)
{
	*fd = open(*input_file, 0);
	if (*fd == -1)
		error(3);
	*i = 0;
	*stat = 1;
}

static	void	read_line(char **line, unsigned i, t_object *obj)
{
	process_line(*line, i, obj);
	ft_strdel(line);
}

int				get_vectors(char *input_file, t_object *obj)
{
	int				fd;
	char			*line;
	unsigned int	i;
	int				stat;
	int				first_line;

	init_var(&fd, &i, &stat, &input_file);
	first_line = 0;
	while (stat != -1 && stat != 0)
	{
		stat = get_next_line(fd, &line);
		if (stat == -1)
			error(7);
		if (first_line == 0)
			if (check_size(&fd, &line, &first_line) == 0)
				return (0);
		if (line)
			read_line(&line, i, obj);
		i++;
	}
	if (obj->z_count == 0)
		obj->z_count = i - 1;
	close(fd);
	return (1);
}
