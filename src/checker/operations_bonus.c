/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:39:51 by bjacobs           #+#    #+#             */
/*   Updated: 2023/01/26 17:21:50 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_stack *a, t_stack *b)
{
	if (a && b && a->top > 1 && b->top > 1)
	{
		ft_swap(&a->array[a->top - 1], &a->array[a->top - 2]);
		ft_swap(&b->array[b->top - 1], &b->array[b->top - 2]);
	}
	else if (a && a->top > 1)
		ft_swap(&a->array[a->top - 1], &a->array[a->top - 2]);
	else if (b && b->top > 1)
		ft_swap(&b->array[b->top - 1], &b->array[b->top - 2]);
}

void	px(t_stack *a, t_stack *b, bool pa)
{
	if (pa)
	{
		if (b->top)
		{
			b->top--;
			a->array[a->top] = b->array[b->top];
			a->top++;
		}
	}
	else
	{
		if (a->top)
		{
			a->top--;
			b->array[b->top] = a->array[a->top];
			b->top++;
		}
	}
}

void	rx(t_stack *a, t_stack *b)
{
	if (a && b)
	{
		rotate_stack(a, false);
		rotate_stack(b, false);
	}
	else if (a)
		rotate_stack(a, false);
	else if (b)
		rotate_stack(b, false);
}

void	rrx(t_stack *a, t_stack *b)
{
	if (a && b)
	{
		rotate_stack(a, true);
		rotate_stack(b, true);
	}
	else if (a)
		rotate_stack(a, true);
	else if (b)
		rotate_stack(b, true);
}
