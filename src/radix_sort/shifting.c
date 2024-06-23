/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:49:19 by bjacobs           #+#    #+#             */
/*   Updated: 2023/01/29 16:49:34 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shift_back(t_stack *a, t_stack *b, int total_shifts)
{
	t_stack	*x;

	if (a)
		x = a;
	else
		x = b;
	if (x->top < 2)
		return (0);
	if (total_shifts >= x->top)
		total_shifts %= x->top;
	if (x->top - total_shifts < x->top / 2)
		total_shifts = -(x->top - total_shifts);
	return (-total_shifts);
}

void	reverse_shift(t_stack *a, t_stack *b, int *shifts)
{
	while (shifts[A] < 0 && shifts[B] < 0)
	{
		rx(a, b);
		shifts[A]++;
		shifts[B]++;
	}
	while (shifts[A] < 0)
	{
		rx(a, NULL);
		shifts[A]++;
	}
	while (shifts[B] < 0)
	{
		rx(NULL, b);
		shifts[B]++;
	}
}

void	shift_stack(t_stack *a, t_stack *b, int *shifts)
{
	while (shifts[A] > 0 && shifts[B] > 0)
	{
		rx(a, b);
		shifts[A]--;
		shifts[B]--;
	}
	while (shifts[A] > 0)
	{
		rx(a, NULL);
		shifts[A]--;
	}
	while (shifts[B] > 0)
	{
		rx(NULL, b);
		shifts[B]--;
	}
}
