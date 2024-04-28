/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 07:48:58 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/28 14:21:58 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	bigsort(t_stack **a, t_stack **b, int *nums)
{
	int	size;
	int	end;

	size = ft_stacksize(*a);
	if (size <= 5)
		return (small_sort(a, b));
	end = determine_end(size);
	numsort(nums, size);
	sort_a(a, b, nums, end);
	sort_b(a, b, nums, size);
	return (0);
}

int	determine_end(int size)
{
	int	end;

	if (size >= 6 && size <= 18)
		end = 3;
	else if (size <= 100)
		end = 15;
	else if (size <= 500)
		end = 45;
	else
		end = 50;
	return (end);
}

void	sort_a(t_stack **a, t_stack **b, int *nums, int end)
{
	int	start;
	int	size;

	start = 0;
	size = ft_stacksize(*a);
	while (*a)
	{
		if ((*a)->number <= nums[start])
		{
			pb(a, b);
			if (ft_stacksize(*b) > 1)
				rb(b);
			increment_range(&start, &end, size);
		}
		else if ((*a)->number <= nums[end])
		{
			pb(a, b);
			if (ft_stacksize(*b) > 1 && (*b)->number < (*b)->next->number)
				sb(b);
			increment_range(&start, &end, size);
		}
		else
			ra(a);
	}
}

void	sort_b(t_stack **a, t_stack **b, int *nums, int size)
{
	while (*b)
	{
		if ((*b)->number == nums[size - 1])
		{
			pa(a, b);
			size--;
		}
		else if ((*b)->next && (*b)->next->number == nums[size - 1])
			sb(b);
		else
			rotate_b_to_max(b, nums, size - 1);
	}
}

void	numsort(int *nums, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (nums[j] > nums[j + 1])
			{
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
