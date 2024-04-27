/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:08:35 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/27 19:46:19 by amouhand         ###   ########.fr       */
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
	}
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack)
	{
		while (*stack)
		{
			tmp = (*stack)-> next;
			ft_stackdelone(*stack);
			*stack = tmp;
		}
		*stack = NULL;
	}
}
void	ft_stackdelone(t_stack *stack)
{
	if (stack)
		free(stack);
}
