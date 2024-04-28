/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:53:58 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/28 13:15:25 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_b_to_max(t_stack **b, int *nums, int size)
{
	int		max;
	int		distance;

	max = get_max_number(*b);
	distance = calculate_distance(b, max);
	if (distance < ft_stacksize(*b) / 2)
		rotate_b_less_than_half(b, nums, size, distance);
	else
		rotate_b_more_than_half(b, distance);
}

void	rotate_b_less_than_half(t_stack **b, int *nums, int size, int distance)
{
	while (distance)
	{
		if ((*b)->next->number == nums[size])
		{
			sb(b);
			break ;
		}
		rb(b);
		distance--;
	}
}

void	rotate_b_more_than_half(t_stack **b, int distance)
{
	distance = ft_stacksize(*b) - distance;
	while (get_max(b) != 0)
	{
		rrb(b);
		distance--;
	}
}

int	calculate_distance(t_stack **b, int max)
{
	int		distance;
	t_stack	*tmp;

	distance = 0;
	tmp = *b;
	while (tmp->number != max)
	{
		distance++;
		tmp = tmp->next;
	}
	return (distance);
}

void	increment_range(int *start, int *end, int size)
{
	if (*start < *end)
		(*start)++;
	if (*end < size - 1)
		(*end)++;
}
