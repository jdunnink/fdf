/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   merge_sort_list.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 16:35:29 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:37:48 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	size_t	get_listlen(t_list *vectors)
{
	size_t i;
	t_list *iter;

	i = 0;
	iter = vectors;
	while (iter)
	{
		iter = iter->next;
		i++;
	}
	return (i);
}

static	void	list_split(t_list **one, t_list **two, size_t len, t_list **v)
{
	unsigned int	i;
	t_list			*trail;

	i = 0;
	*one = *v;
	while (i < len / 2)
	{
		trail = *v;
		*v = (*v)->next;
		i++;
	}
	trail->next = NULL;
	*two = *v;
}

static t_list	*push(t_list *list, t_list **new, unsigned *i)
{
	t_list	*dest;
	t_list	*iter;

	(*i)++;
	if (list == NULL)
	{
		dest = *new;
		*new = (*new)->next;
		dest->next = NULL;
		return (dest);
	}
	iter = list;
	while (iter->next)
		iter = iter->next;
	iter->next = *new;
	*new = (*new)->next;
	iter = iter->next;
	iter->next = NULL;
	dest = list;
	return (dest);
}

static	t_list	*merge(t_list *one, t_list *two, t_vec *v_one, t_vec *v_two)
{
	t_list		*dest;
	t_list		*iter;
	size_t		dest_len;
	unsigned	i;

	i = 0;
	dest = NULL;
	dest_len = get_listlen(one) + get_listlen(two);
	while (i < dest_len)
	{
		if (!one)
			dest = push(dest, &two, &i);
		else if (!two)
			dest = push(dest, &one, &i);
		else
		{
			v_two = two->content;
			v_one = one->content;
			if (v_one->x < v_two->x)
				dest = push(dest, &one, &i);
			else
				dest = push(dest, &two, &i);
		}
	}
	return (dest);
}

t_list			*merge_sort_list(t_list *vectors)
{
	size_t	list_len;
	t_list	*one;
	t_list	*two;
	t_vec	*v_one;
	t_vec	*v_two;

	one = NULL;
	two = NULL;
	if (list_len == 1 || vectors->next == 0)
		return (vectors);
	list_len = get_listlen(vectors);
	list_split(&one, &two, list_len, &vectors);
	return (merge(merge_sort_list(one), merge_sort_list(two), v_one, v_two));
}
