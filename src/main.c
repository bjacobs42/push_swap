/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:34:13 by bjacobs           #+#    #+#             */
/*   Updated: 2023/02/01 18:58:13 by bjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	put_err(char *s)
{
	ft_putendl_fd(s, STDERR_FILENO);
}

int	main(int ac, char **av)
{
	char	**lst;
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (EXIT_SUCCESS);
	lst = create_args(av);
	if (!lst)
		return (put_err("Error"), EXIT_FAILURE);
	ac = lstlen(lst);
	a = init_stack(ac, lst);
	ft_clear_lst(lst);
	if (!a.array)
		return (put_err("Error"), EXIT_FAILURE);
	b = init_stack(ac, NULL);
	if (!b.array)
		return (destroy_stack(&a, &b), put_err("Error"), EXIT_FAILURE);
	if (ac < 20)
		simple_sort(a, b);
	else
	{
		toi(&a);
		radix_sort(a, b);
	}
	return (destroy_stack(&a, &b), EXIT_SUCCESS);
}
