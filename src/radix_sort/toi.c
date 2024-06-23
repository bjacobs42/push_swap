/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:43:49 by bjacobs           #+#    #+#             */
/*   Updated: 2023/01/29 12:20:44 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	*arrdup(int *array, size_t size)
{
	int	*dup;

	dup = (int *)malloc(sizeof(int) * size);
	if (!dup)
		return (NULL);
	while (size--)
		dup[size] = array[size];
	return (dup);
}

static int	*bubble_sort(int *array, size_t size)
{
	size_t	i;

	while (!sorted(array, size, true))
	{
		i = size;
		while (--i)
		{
			if (array[i] < array[i - 1])
				ft_swap(&array[i], &array[i - 1]);
		}
	}
	return (array);
}

static int	*to_index(int *sorted_array, int *array, size_t size)
{
	size_t	i;
	size_t	j;
	int		*storage;

	storage = (int *)malloc(sizeof(int) * size);
	if (!storage)
		return (NULL);
	i = size;
	while (i--)
	{
		j = size;
		while (j--)
		{
			if (sorted_array[j] == array[i])
				storage[i] = j;
		}
	}
	return (storage);
}

int	toi(t_stack *a)
{
	int	*array;
	int	*storage;

	array = arrdup(a->array, a->top);
	if (!array)
		return (1);
	array = bubble_sort(array, a->top);
	storage = to_index(array, a->array, a->top);
	if (!storage)
		return (1);
	free(array);
	free(a->array);
	a->array = storage;
	return (0);
}
