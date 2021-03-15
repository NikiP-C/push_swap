/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nphilipp <nphilipp@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 19:08:48 by nphilipp      #+#    #+#                 */
/*   Updated: 2021/03/15 16:57:32 by nphilipp      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "CodamGNL/get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

void	error(int error_hand)
{
	exit(error_hand);
}

void	do_sasb(int *list)
{
	int	i;

	i = list[0];
	list[0] = list[1];
	list[1] = i;
}

int	sorter(int *list_a, int count)
{
	int		gnl_ret;
	char	*str;

	gnl_ret = 1;
	while (gnl_ret == 1)
	{
		gnl_ret = get_next_line(0, &str);
		if (ft_strcmp(str, "sa", 3))
			do_sasb(&list_a);
		else if (ft_strncmp(str, "sb", 3))
			do_sasb(&list_a);
		else if (ft_strncmp(str, "ss", 3))
			do_ss(&list_a);
		else if (ft_strncmp(str, "pa", 3))
			do_pa(&list_a);
		else if (ft_strncmp(str, "pb", 3))
			do_sb(&list_a);
		else if (ft_strncmp(str, "ra", 3))
			do_sb(&list_a);
		else if (ft_strncmp(str, "rb", 3))
			do_ss(&list_a);
		else if (ft_strncmp(str, "rr", 3))
			do_pa(&list_a);
		else if (ft_strncmp(str, "rra", 4))
			do_sb(&list_a);
		else if (ft_strncmp(str, "rrb", 4))
			do_sb(&list_a);
		else if (ft_strncmp(str, "rrr", 4))
			do_sb(&list_a);
	}
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
