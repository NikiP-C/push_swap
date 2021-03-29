/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nphilipp <nphilipp@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 19:08:48 by nphilipp      #+#    #+#                 */
/*   Updated: 2021/03/29 17:29:25 by nphilipp      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "CodamGNL/get_next_line.h"
#include "libft/libft.h"
#include "checker.h"
#include <stdio.h>

void	error(int error_hand)
{
	exit(error_hand);
}


int	check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (ft_isstrnum(&str[i]))
		return (ft_atoi(str));
	error(2);
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	int		*list_a;

	i = 0;
	if (ac == 1)
		return (0);
	list_a = malloc(sizeof(int) * (ac - 1));
	if (list_a == 0)
		error(3);
	while (i < (ac - 1))
	{
		list_a[i] = check(av[i + 1]);
		i++;
	}
	ft_print_int_array_fd(list_a, (ac - 1), '\n', 1);
	sorter(list_a, ac - 1);
}
