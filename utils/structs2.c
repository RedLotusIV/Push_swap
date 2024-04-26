/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:12:21 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/13 16:04:18 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
		return (NULL);
	last = stack;
	while (last->next)
		last = last->next;
	return (last);
}
int	ft_stacksize(t_stack *stack)
{
	int		i;
	t_stack	*head;

	if (!stack)
		return (0);
	head = stack;
	i = 0;
	while (head != NULL)
	{
		head = head -> next;
		i++;
	}
	return (i);
}
int	get_min(t_stack **stack)
{
	t_stack	*tmp;
	int		min;
	int index;

	index = 0;
	tmp = *stack;
	min = tmp->number;
	while (tmp)
	{
		if (min > tmp->number)
		{
			min = tmp->number;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index);
}
int	get_distance(t_stack **stack, int index)
{
	t_stack	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}
int	reset_index(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
	if(!b || !*b)
		return (0);
	tmp = *b;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
	return (0);
}
int	struct_is_sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}