/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:03:51 by amouhand          #+#    #+#             */
/*   Updated: 2024/05/05 15:35:29 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return;
	tmp = ft_stacknew(0, 0);
	if (!tmp)
		return;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp->next->next;
	tmp->next->next = *stack;
	*stack = tmp->next;
	reset_index(stack, NULL);
	free(tmp);
}

void	ft_push(t_stack **from, t_stack **to)
{
	t_stack	*new_node;
	t_stack	*temp;

	if (!from || !*from || !to)
		return;
	new_node = ft_stacknew((*from)->index, (*from)->number);
	if (!new_node)
		return;
	ft_stackadd_front(to, new_node);
	temp = *from;
	*from = (*from)->next;
	reset_index(from, to);
	free(temp);
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	if (!stack || !*stack)
		return;
	head = *stack;
	last = ft_stacklast(*stack);
	*stack = head->next;
	head->next = NULL;
	last->next = head;
	reset_index(stack, NULL);
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*before_last;
	t_stack	*last;

	if (!stack || !*stack)
		return;
	before_last = *stack;
	last = ft_stacklast(*stack);
	while (before_last->next != last)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	reset_index(stack, NULL);
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}
