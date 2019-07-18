/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/15 17:02:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 18:25:18 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_valid_nbr(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0 && ft_issign(str[i]) == 0)
			return (0);
		if (ft_issign(str[i]) == 1 && i != 0)
			return (0);
		i++;
	}
	return (1);
}

int		is_alt_nbr(char *str)
{
	while (*str != '\0')
	{
		if (ft_cinstr(",0xabcdefABCDEF0123456789", *str) == 0)
			return (0);
		str++;
	}
	return (1);
}

int		extract_nbr(char *str)
{
	char	*dest;
	char	*tmp;
	size_t	len;
	int		num;

	len = 0;
	tmp = str;
	while (*tmp != ',')
	{
		len++;
		tmp++;
	}
	dest = ft_strnew(len);
	dest = ft_strncpy(dest, str, len);
	num = ft_atoi(dest);
	free(dest);
	return (num);
}
