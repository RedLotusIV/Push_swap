/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:39:09 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/28 11:47:01 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max(t_stack **stack)
{
	t_stack	*tmp;
	int		max;
	int		index;

	index = 0;
	tmp = *stack;
	max = tmp->number;
	while (tmp)
	{
		if (max < tmp->number)
		{
			max = tmp->number;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index);
}

int	get_max_number(t_stack *stack)
{
	int		max_number;
	t_stack	*tmp;

	max_number = stack->number;
	tmp = stack;
	while (tmp)
	{
		if (tmp->number > max_number)
			max_number = tmp->number;
		tmp = tmp->next;
	}
	return (max_number);
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
