/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:56:14 by bjacobs           #+#    #+#             */
/*   Updated: 2023/01/29 17:04:28 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	lined_up(t_stack x, size_t bitshifts, int remaining, int shifts)
{
	int	amount;
	int	i;

	amount = 0;
	i = x.top;
	while (i--)
	{
		if (!check_bit(x.array[i], bitshifts, true)
			|| !check_bit(x.array[i], bitshifts + 1, true))
			break ;
		amount++;
	}
	if (amount == remaining && amount + shifts == x.top)
		return (true);
	return (false);
}

static int	fill_bucket(t_stack *a, t_stack *b, size_t bitshifts, int *shifts)
{
	int	remaining;
	int	total_shifts;

	total_shifts = 0;
	remaining = numbers_remain(*a, bitshifts);
	while (remaining--)
	{
		if (lined_up(*a, bitshifts, remaining + 1, total_shifts))
		{
			total_shifts = 0;
			break ;
		}
		shifts[A] = nearest_number(*a, bitshifts, true);
		total_shifts += shifts[A];
		shift_stack(a, b, shifts);
		reverse_shift(a, b, shifts);
		px(a, b, false);
	}
	return (shift_back(a, NULL, total_shifts));
}

static int	empty_bucket(t_stack *a, t_stack *b, size_t bitshifts, int *shifts)
{
	int	remaining;
	int	total_shifts;

	total_shifts = 0;
	remaining = numbers_remain(*b, bitshifts + 1);
	while (remaining < b->top)
	{
		shifts[B] = nearest_number(*b, bitshifts + 1, false);
		total_shifts += shifts[B];
		shift_stack(a, b, shifts);
		reverse_shift(a, b, shifts);
		px(a, b, true);
	}
	return (shift_back(NULL, b, total_shifts));
}

void	radix_sort(t_stack a, t_stack b)
{
	int		shifts[2];
	size_t	max_bits;
	size_t	bitshifts;

	bitshifts = 0;
	shifts[B] = 0;
	max_bits = count_bits(get_biggest(a.array, a.top));
	while (bitshifts < max_bits && (!sorted(a.array, a.top, false) || b.top))
	{
		shifts[A] = fill_bucket(&a, &b, bitshifts, shifts);
		shifts[B] = empty_bucket(&a, &b, bitshifts, shifts);
		bitshifts++;
	}
	while (b.top)
		px(&a, &b, true);
}
