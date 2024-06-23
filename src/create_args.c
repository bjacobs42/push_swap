/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_args.c                                      :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: bjacobs <bjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 18:20:26 by bjacobs       #+#    #+#                 */
/*   Updated: 2023/02/12 19:32:53 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

size_t	lstlen(char **lst)
{
	size_t	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst[i])
		i++;
	return (i);
}

static char	**join_lst(char **lst1, char **lst2)
{
	char	**new;
	int		size1;
	int		size2;

	size1 = lstlen(lst1);
	size2 = lstlen(lst2);
	new = (char **)malloc(sizeof(char *) * (size1 + size2 + 1));
	if (!new)
		return (ft_clear_lst(lst1), NULL);
	new[size1 + size2] = NULL;
	while (size2--)
		new[size1 + size2] = lst2[size2];
	while (size1--)
		new[size1] = lst1[size1];
	free(lst1);
	return (new);
}

static bool	parse_lst(char **lst)
{
	int	i;

	i = 0;
	if (!lst[i])
		return (false);
	while (lst[i])
	{
		if (!parse_str(lst[i]))
			return (false);
		i++;
	}
	return (true);
}

char	**create_args(char **av)
{
	char	**lst;
	char	**temp;
	size_t	i;

	i = 1;
	lst = NULL;
	while (av[i])
	{
		if (!av[i][0])
			return (ft_clear_lst(lst), NULL);
		temp = ft_split(av[i], ' ');
		if (!temp)
			return (ft_clear_lst(lst), NULL);
		if (!parse_lst(temp))
			return (ft_clear_lst(temp), ft_clear_lst(lst), NULL);
		lst = join_lst(lst, temp);
		if (!lst)
			return (ft_clear_lst(temp), NULL);
		free(temp);
		i++;
	}
	return (lst);
}
