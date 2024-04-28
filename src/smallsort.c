/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 07:49:07 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/28 12:42:38 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_2(t_stack **a)
{
	if ((*a)->number > (*a)->next->number)
		sa(a);
	return (0);
}

int	sort_3(t_stack **a)
{
	if (ft_stacksize(*a) < 3)
		return (-1);
	if (struct_is_sorted(a))
		return (0);
	if ((*a)->number > (*a)->next->number
		&& (*a)->number > (*a)->next->next->number)
	{
		ra(a);
		if ((*a)->number > (*a)->next->number)
			sa(a);
	}
	else if ((*a)->number > (*a)->next->number
		&& (*a)->number < (*a)->next->next->number)
		sa(a);
	else if ((*a)->number < (*a)->next->number
		&& (*a)->number > (*a)->next->next->number)
		rra(a);
	else if ((*a)->number < (*a)->next->number
		&& (*a)->number < (*a)->next->next->number)
	{
		rra(a);
		if ((*a)->number > (*a)->next->number)
			sa(a);
	}
	return (0);
}

int	sort_4(t_stack **a, t_stack **b)
{
	int	distance;

	if (ft_stacksize(*a) < 4)
		return (-1);
	if (struct_is_sorted(a))
		return (0);
	distance = get_distance(a, get_min(a));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
		rra(a);
	if (struct_is_sorted(a))
		return (0);
	pb(a, b);
	sort_3(a);
	pa(a, b);
	return (0);
}

int	sort_5(t_stack **a, t_stack **b)
{
	int	distance;

	if (struct_is_sorted(a))
		return (0);
	distance = get_distance(a, get_min(a));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
	{
		rra(a);
		rra(a);
	}
	else if (distance == 4)
		rra(a);
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
	return (0);
}

int	small_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stacksize(*a);
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
	return (0);
}
