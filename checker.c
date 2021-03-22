/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nphilipp <nphilipp@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 19:08:48 by nphilipp      #+#    #+#                 */
/*   Updated: 2021/03/22 18:52:36 by nphilipp      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "CodamGNL/get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

void	error(int error_hand)
{
	exit(error_hand);
}

void	swap_first(t_list *head)
{
	void	*info;

	info = head->content;
	head->content = head->next->content;
	head->next->content = info;
}

void	push_first(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	ft_lstadd_front(head_a, *head_b);
	tmp = (*head_b)->next;
	free(*head_b);
	head_b = &tmp;
}


void	rotate(t_list **head)
{
	ft_lstadd_back(head, *head);
	head = &(*head)->next;
}

int	sorter(int *list_a, int *list_b, int count)
{
	int		gnl_ret;
	char	*str;

	gnl_ret = 1;
	while (gnl_ret == 1)
	{
		gnl_ret = get_next_line(0, &str);
		if (ft_strcmp(str, "sa", 3) || ft_strcmp(str, "ss", 3))
			swap_first(&list_a);
		if (ft_strncmp(str, "sb", 3) || ft_strcmp(str, "ss", 3))
			swap_first(&list_b);
		else if (ft_strncmp(str, "pa", 3))
			push_first(&list_a, &list_b);
		else if (ft_strncmp(str, "pb", 3))
			push_first(&list_b, &list_a);
		else if (ft_strncmp(str, "ra", 3) || ft_strncmp(str, "rr", 3))
			rotate(&list_a);
		else if (ft_strncmp(str, "rb", 3) || ft_strncmp(str, "rr", 3))
			rotate(&list_b);
		else if (ft_strncmp(str, "rra", 4) || ft_strncmp(str, "rrr", 4))
			reverse_rotate(&list_a);
		else if (ft_strncmp(str, "rrb", 4) || ft_strncmp(str, "rrr", 4))
			reverse_rotate(&list_b);
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
