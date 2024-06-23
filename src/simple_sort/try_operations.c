/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:33:06 by bjacobs           #+#    #+#             */
/*   Updated: 2023/01/28 18:52:41 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_top(int num)
{
	return (num > 1);
}

static void	try_function(t_stack *a, t_stack *b, bool *c,
		void (*f)(t_stack *a, t_stack *b))
{
	if (c[A] && c[B])
		f(a, b);
	else if (c[A])
		f(a, NULL);
	else if (c[B])
		f(NULL, b);
}

void	try_rrx(t_stack *a, t_stack *b)
{
	int		i;
	bool	change[2];

	i = 0;
	change[A] = check_top(a->top);
	while (change[A] && ++i < a->top)
	{
		if (a->array[0] > a->array[i])
			change[A] = false;
	}
	i = 0;
	change[B] = check_top(b->top);
	while (change[B] && ++i < b->top)
	{
		if (b->array[0] < b->array[i])
			change[B] = false;
	}
	try_function(a, b, change, &rrx);
}

void	try_rx(t_stack *a, t_stack *b)
{
	int		i;
	bool	change[2];

	i = a->top;
	change[A] = check_top(a->top);
	while (change[A] && i--)
	{
		if (a->array[a->top - 1] < a->array[i])
			change[A] = false;
	}
	i = b->top;
	change[B] = check_top(b->top);
	while (change[B] && i--)
	{
		if (b->array[b->top - 1] > b->array[i])
			change[B] = false;
	}
	try_function(a, b, change, &rx);
}

void	try_sx(t_stack *a, t_stack *b)
{
	bool	change[2];

	if (a->top > 1 && a->array[a->top - 1] > a->array[a->top - 2])
		change[A] = true;
	else
		change[A] = false;
	if (b->top > 1 && b->array[b->top - 1] < b->array[b->top - 2])
		change[B] = true;
	else
		change[B] = false;
	try_function(a, b, change, &sx);
}
