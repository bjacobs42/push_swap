/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:39:51 by bjacobs           #+#    #+#             */
/*   Updated: 2023/01/28 18:52:12 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_stack *a, t_stack *b)
{
	if (a && b && a->top > 1 && b->top > 1)
	{
		ft_swap(&a->array[a->top - 1], &a->array[a->top - 2]);
		ft_swap(&b->array[b->top - 1], &b->array[b->top - 2]);
		ft_putendl_fd("ss", STDOUT_FILENO);
	}
	else if (a && a->top > 1)
	{
		ft_swap(&a->array[a->top - 1], &a->array[a->top - 2]);
		ft_putendl_fd("sa", STDOUT_FILENO);
	}
	else if (b && b->top > 1)
	{
		ft_swap(&b->array[b->top - 1], &b->array[b->top - 2]);
		ft_putendl_fd("sb", STDOUT_FILENO);
	}
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
		ft_putendl_fd("pa", STDOUT_FILENO);
	}
	else
	{
		if (a->top)
		{
			a->top--;
			b->array[b->top] = a->array[a->top];
			b->top++;
		}
		ft_putendl_fd("pb", STDOUT_FILENO);
	}
}

void	rx(t_stack *a, t_stack *b)
{
	if (a && b)
	{
		rotate_stack(a, false);
		rotate_stack(b, false);
		ft_putendl_fd("rr", STDOUT_FILENO);
	}
	else if (a)
	{
		rotate_stack(a, false);
		ft_putendl_fd("ra", STDOUT_FILENO);
	}
	else if (b)
	{
		rotate_stack(b, false);
		ft_putendl_fd("rb", STDOUT_FILENO);
	}
}

void	rrx(t_stack *a, t_stack *b)
{
	if (a && b)
	{
		rotate_stack(a, true);
		rotate_stack(b, true);
		ft_putendl_fd("rrr", STDOUT_FILENO);
	}
	else if (a)
	{
		rotate_stack(a, true);
		ft_putendl_fd("rra", STDOUT_FILENO);
	}
	else if (b)
	{
		rotate_stack(b, true);
		ft_putendl_fd("rrb", STDOUT_FILENO);
	}
}
