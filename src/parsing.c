/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:33:54 by bjacobs           #+#    #+#             */
/*   Updated: 2023/02/02 19:32:28 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static int	cmp_max_int(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+')
		i++;
	while (s[i] == '0')
		i++;
	if (ft_strlen(&s[i]) < 10)
		return (0);
	return (ft_strncmp(&s[i], "2147483647", 11));
}

static int	cmp_min_int(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i] == '0')
		i++;
	if (ft_strlen(&s[i]) < 10)
		return (0);
	return (ft_strncmp(&s[i], "2147483648", 11));
}

// check how to do this1
bool	parse_str(char *s)
{
	int	i;

	if (!s[0])
		return (false);
	i = 0;
	if (s[i] == '-' && s[i + 1])
	{
		if (cmp_min_int(s) > 0)
			return (false);
		i++;
	}
	else
	{
		if (s[i] == '+' && s[i + 1])
			i++;
		if (cmp_max_int(s) > 0)
			return (false);
	}
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	doubles(int *array, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
