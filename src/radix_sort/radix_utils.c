/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:59:06 by bjacobs           #+#    #+#             */
/*   Updated: 2023/01/29 17:05:08 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_bits(int x)
{
	size_t	bits;

	bits = 0;
	while (x >> bits)
		bits++;
	return (bits);
}

int	get_biggest(int *array, size_t size)
{
	int	biggest;

	if (!array || !size)
		return (0);
	biggest = array[0];
	while (size--)
	{
		if (array[size] > biggest)
			biggest = array[size];
	}
	return (biggest);
}

bool	check_bit(int num, int bitshifts, bool zero)
{
	if (zero)
		return (!((num >> bitshifts) & 1));
	return (((num >> bitshifts) & 1));
}

int	numbers_remain(t_stack x, int bitshifts)
{
	int	amount;

	amount = 0;
	while (x.top--)
	{
		if (check_bit(x.array[x.top], bitshifts, true))
			amount++;
	}
	return (amount);
}

int	nearest_number(t_stack x, int bitshifts, bool zero)
{
	int		shifts;

	shifts = 0;
	while (x.top--)
	{
		if (check_bit(x.array[x.top], bitshifts, zero))
			break ;
		shifts++;
	}
	return (shifts);
}
