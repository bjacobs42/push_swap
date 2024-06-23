/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:05:40 by bjacobs           #+#    #+#             */
/*   Updated: 2023/02/01 19:00:47 by bjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	rotate_stack(t_stack *x, bool reverse)
{
	int	i;

	if (x->top < 2)
		return ;
	if (reverse)
	{
		i = 0;
		while (i < x->top - 1)
		{
			ft_swap(&x->array[i], &x->array[i + 1]);
			i++;
		}
	}
	else
	{
		i = x->top;
		while (--i > 0)
			ft_swap(&x->array[i], &x->array[i - 1]);
	}
}

bool	sorted(int *array, size_t size, bool reverse)
{
	if (!size)
		return (true);
	while (--size)
	{
		if (!reverse && array[size] > array[size - 1])
			return (false);
		else if (reverse && array[size] < array[size - 1])
			return (false);
	}
	return (true);
}

void	destroy_stack(t_stack *a, t_stack *b)
{
	if (a && a->array)
	{
		free(a->array);
		a->array = NULL;
	}
	if (b && b->array)
	{
		free(b->array);
		b->array = NULL;
	}
}

t_stack	init_stack(int ac, char **av)
{
	t_stack	stack;
	int		i;

	stack.array = (int *)malloc(sizeof(int) * ac);
	if (!stack.array)
		return (stack);
	if (!av)
	{
		stack.top = 0;
		return (stack);
	}
	stack.top = ac;
	i = 0;
	while (i < ac)
	{
		stack.array[ac - i - 1] = ft_atoi(av[i]);
		i++;
	}
	if (doubles(stack.array, stack.top))
		destroy_stack(&stack, NULL);
	return (stack);
}
