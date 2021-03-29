/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorter.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nphilipp <nphilipp@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 17:27:57 by nphilipp      #+#    #+#                 */
/*   Updated: 2021/03/29 17:30:33 by nphilipp      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "CodamGNL/get_next_line.h"
#include "libft/libft.h"
#include "checker.h"

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

void	reverse_rotate(t_list **head)
{
	t_list	*tmp;

	while (tmp->next->next != NULL)
		tmp = tmp->next;
	ft_lstadd_front(head, tmp->next);
	tmp->next = NULL;
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