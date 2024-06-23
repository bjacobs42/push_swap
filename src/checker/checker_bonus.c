/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:34:13 by bjacobs           #+#    #+#             */
/*   Updated: 2023/02/02 19:20:20 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"
#include <stdlib.h>

static void	put_err(char *s)
{
	ft_putendl_fd(s, STDERR_FILENO);
}

static int	exec_instruc(char *instruction, t_stack *a, t_stack *b)
{
	if (ft_strncmp(instruction, "pa\n", 3) == 0)
		px(a, b, true);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		px(a, b, false);
	else if (ft_strncmp(instruction, "sa\n", 3) == 0)
		sx(a, NULL);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		sx(NULL, b);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		sx(a, b);
	else if (ft_strncmp(instruction, "ra\n", 3) == 0)
		rx(a, NULL);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rx(NULL, b);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rx(a, b);
	else if (ft_strncmp(instruction, "rra\n", 3) == 0)
		rrx(a, NULL);
	else if (ft_strncmp(instruction, "rrb\n", 3) == 0)
		rrx(NULL, b);
	else if (ft_strncmp(instruction, "rrr\n", 3) == 0)
		rrx(a, b);
	else
		return (-1);
	return (0);
}

static int	check(t_stack a, t_stack b)
{
	char	*instruction;
	int		fd;

	fd = STDIN_FILENO;
	instruction = get_next_line(fd);
	while (instruction)
	{
		if (exec_instruc(instruction, &a, &b) == -1)
			return (free(instruction), -1);
		free(instruction);
		instruction = get_next_line(fd);
	}
	if (!sorted(a.array, a.top, false) || b.top)
		ft_putendl_fd("KO", STDOUT_FILENO);
	else
		ft_putendl_fd("OK", STDOUT_FILENO);
	return (0);
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
	if (check(a, b) == -1)
		return (ft_putendl_fd("Error", STDERR_FILENO), EXIT_FAILURE);
	return (destroy_stack(&a, &b), EXIT_SUCCESS);
}
