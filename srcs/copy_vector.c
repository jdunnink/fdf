/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   copy_vectors.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 21:12:37 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/07/15 21:12:37 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list *copy_vector(t_list *elem)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = (t_vec *)malloc(elem->content_size);
	new->content = ft_memcpy(new->content, elem->content, elem->content_size);
	new->content_size = elem->content_size;
	new->next = NULL;
	return (new);
}