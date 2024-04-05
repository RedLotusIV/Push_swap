/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 07:48:58 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/05 15:15:15 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
int	bigsort(t_stack **a, t_stack **b, int *nums)
{
	int size;
	int start;
	int end;
	int offset;
	int mid;
	int counter;
	int j = 0;
	t_stack *tmp;

	size = ft_stacksize(*a);
	tmp = *a;
	if (size <= 5)
		return (small_sort(a, b));
	counter = 0;
	offset = size / (size / 2);
	mid = size / 2 - 1;
	start = mid - offset;
	end = mid + offset;
	numsort(nums, size);
	while (*a)
	{
		if ((*a)->number > nums[start] && (*a)->number <= nums[end])
		{
			pb(a, b);
			if (ft_stacksize(*b) > 1 && (*b)->number > nums[mid])
				rb(b);
			tmp = *a;
		}
		else
		{
			while (tmp && (tmp->number < nums[start] || tmp->number > nums[end]))
			{
				counter++;
				tmp = tmp->next;
			}
			if (counter >= ft_stacksize(*a))
			{
				start -= offset;
				end += offset;
				if (start < 0)
					start = 0;
				if (end > size - 1)
					end = size - 1;
				counter = 0;
				j = 0;
			}
			else
			{
				while(j < counter)
				{
					ra(a);
					j++;
				}
				pb(a, b);
				counter = 0;
				j = 0;
			}
			tmp = *a;
		}
	}
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
		while(j < n - i - 1)
		{
			if (nums[j] > nums[j+1])
			{
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
			j++;
		}
		i++;
	}
}
