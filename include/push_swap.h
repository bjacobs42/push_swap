/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:34:44 by bjacobs           #+#    #+#             */
/*   Updated: 2023/02/01 18:52:22 by bjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define A 0
# define B 1

# include "libft.h"
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack
{
	int	top;
	int	*array;
}		t_stack;

/* * * * stack stuff * * * */
t_stack	init_stack(int ac, char **av);
void	destroy_stack(t_stack *a, t_stack *b);
void	rotate_stack(t_stack *x, bool reverse);
void	sx(t_stack *a, t_stack *b);
void	px(t_stack *a, t_stack *b, bool pa);
void	rx(t_stack *a, t_stack *b);
void	rrx(t_stack *a, t_stack *b);

bool	sorted(int *array, size_t size, bool reverse);

/* * * * simple sort * * * */
void	simple_sort(t_stack a, t_stack b);
void	try_rx(t_stack *a, t_stack *b);
void	try_rrx(t_stack *a, t_stack *b);
void	try_sx(t_stack *a, t_stack *b);

/* * * * radix sort * * * */
void	radix_sort(t_stack a, t_stack b);
void	shift_stack(t_stack *a, t_stack *b, int *shifts);
void	reverse_shift(t_stack *a, t_stack *b, int *shifts);

int		shift_back(t_stack *a, t_stack *b, int total_shifts);
int		numbers_remain(t_stack x, int bitshifts);
int		nearest_number(t_stack x, int bitshifts, bool zero);
int		get_biggest(int *array, size_t size);
int		toi(t_stack *a);

size_t	count_bits(int x);

bool	check_bit(int num, int bitshifts, bool zero);

/* * * * create arguments * * * */
char	**create_args(char **av);

size_t	lstlen(char **lst);

/* * * * parsing * * * */
bool	parse_str(char *s);
bool	doubles(int *array, size_t size);

#endif
