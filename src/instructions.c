/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:03:51 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/13 16:03:52 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
int ft_swap(t_stack **stack)
{
	t_stack *tmp;

	if (!stack || !*stack || !(*stack)->next )
		return (-1);
	tmp = ft_stacknew(0, 0);
	if (!tmp)
		return	(-1);
	tmp->next = (*stack)->next;
	// swapping
	(*stack)->next = tmp->next->next;
	tmp->next->next = *stack;
	*stack = tmp->next;
	reset_index(stack, NULL);
	free(tmp);
	return (0);
}
int ft_push(t_stack **from, t_stack **to)
{
	t_stack *new_node;
	
    if (!from || !*from || !to)
        return (-1);
    new_node = ft_stacknew((*from)->index, (*from)->number);
    if (!new_node)
        return (-1);
    ft_stackadd_front(to, new_node);
    t_stack *temp = *from;
    *from = (*from)->next;
	reset_index(from, to);
    free(temp);
	return (0);
}
int ft_rotate(t_stack **stack)
{
	t_stack *head;
	t_stack *last;

	if (!stack || !*stack)
		return (-1);
	head = *stack;
	last = ft_stacklast(*stack);
	// rotating
	*stack = head->next;
	head->next = NULL;
	last->next = head;
	reset_index(stack, NULL);
	return (0);
}
int ft_reverse_rotate(t_stack **stack)
{
	t_stack *before_last;
	t_stack *last;

	if (!stack || !*stack)
		return (-1);
	before_last = *stack;
	last = ft_stacklast(*stack);
	while(before_last->next != last)
		before_last = before_last->next;
	// rotating
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	reset_index(stack, NULL);
	return (0);
}
void rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}