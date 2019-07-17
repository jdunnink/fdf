/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_vectors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 17:15:57 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/17 20:35:18 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	print(t_vec *curr)
{
	ft_putnbr((int)curr->x);
	ft_putstr(" ,");
	ft_putnbr((int)curr->y);
	ft_putstr(" ,");
	ft_putnbr((int)curr->z);
	ft_putstr(" ,");
	ft_putnbr((int)curr->br);
	ft_putchar('\n');
}

void	print_vectors(t_list *vectors, int mode)
{
	t_list	*iter;
	t_vec	*curr;
	unsigned int i;

	i = 0;
	iter = vectors;
	while (iter != NULL)
	{
		curr = iter->content;
		if (mode == 1)
			print(curr);
		iter = iter->next;
		i++;
	}
	printf("total vectors printed: %u\n", i);
}
