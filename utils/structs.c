/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:08:35 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/01 03:56:41 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stacknew(int index, int number)
{
	t_stack	*head;

	head = (t_stack *)malloc(sizeof(*head));
	if (head == NULL)
		return (NULL);
	head -> index = index;
	head -> number = number;
	head -> prev = NULL;
	head -> next = NULL;
	return (head);
}
void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (stack)
	{
		if (*stack)
			new -> next = *stack;
		*stack = new;
		if (new -> next)
			new -> next -> prev = new;
	}
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*store;

	if (!stack)
		return ;
	ptr = *stack;
	store = NULL;
	while (ptr)
	{
		store = ptr->next;
		ft_stackdelone(ptr);
		ptr = store;
	}
	*stack = NULL;
}
void	ft_stackdelone(t_stack *stack)
{
	if (stack)
		free(stack);
}
