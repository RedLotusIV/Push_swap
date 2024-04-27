/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 07:48:58 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/27 17:31:42 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
int	bigsort(t_stack **a, t_stack **b, int *nums)
{
	int		size;
	int		start;
	int		end;

	size = ft_stacksize(*a);
	if (size <= 5)
		return (small_sort(a, b));
	start = 0;
	if (size >= 6 && size <= 18)
		end = 3;
	else if (size <= 100)
		end = 15;
	else if (size <= 500)
		end = 45;
	else
		end = 50;
	numsort(nums, size);
	while (*a)
	{
		if ((*a)->number <= nums[start])
		{
			pb(a, b);
			if (ft_stacksize(*b) > 1)
				rb(b);
			if (start < end)
				start++;
			if (end < size - 1)
				end++;
		}
		else if ((*a)->number <= nums[end])
		{
			pb(a, b);
			if (ft_stacksize(*b) > 1 && (*b)->number < (*b)->next->number)
				sb(b);
			if (start < end)
				start++;
			if (end < size - 1)
				end++;
		}
		else
			ra(a);

	}
	while (*b)
		if ((*b)->number == nums[size - 1])
		{
			pa(a, b);
			size--;
		}
		else if ((*b)->next && (*b)->next->number == nums[size - 1])
			sb(b);
		else
			rotate_b_to_max(b, nums, size - 1);
	return (0);
}
void numsort(int *nums, int n)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	while (i < n - 1)
	{
		j = 0;
		while(j < n - i - 1)
		{
			if (nums[j] > nums[j+1])
			{
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
void rotate_b_to_max(t_stack **b, int *nums, int size)
{
	int max;
	t_stack *tmp;
	int distance;

	distance = 0;
	tmp = *b;
	max = get_max_number(*b);
	while (tmp->number != max)
	{
		distance++;
		tmp = tmp->next;
	}
	if (distance < ft_stacksize(*b) / 2)
	{
		while (distance)
		{
			if ((*b)->next->number == nums[size])
			{
				sb(b);
				break;
			}
			rb(b);
			distance--;

		}
	}
	else
	{
		distance = ft_stacksize(*b) - distance;
		while (get_max(b) != 0)
		{
			rrb(b);
			distance--;
		}
	}
}

