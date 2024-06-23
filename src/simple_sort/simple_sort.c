/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.cc                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:45:43 by bjacobs           #+#    #+#             */
/*   Updated: 2023/01/28 18:45:51 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack a, t_stack b)
{
	while (!sorted(a.array, a.top, false))
	{
		while (!sorted(a.array, a.top, false))
		{
			try_rx(&a, &b);
			try_rrx(&a, &b);
			try_sx(&a, &b);
			if (a.top > 2 && !sorted(a.array, a.top, false))
				px(&a, &b, false);
		}
		while (b.top && sorted(a.array, a.top, false))
		{
			try_rx(&a, &b);
			try_rrx(&a, &b);
			try_sx(&a, &b);
			if (b.top && sorted(a.array, a.top, false))
				px(&a, &b, true);
		}
	}
}
