/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 07:48:58 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/27 16:39:11 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
int	bigsort(t_stack **a, t_stack **b, int *nums)
{
	int		size;
	int		mid;
	int		start;
	int		end;
	int		counter;
	int		offset;
	t_stack	*tmp;

	size = ft_stacksize(*a);
	tmp = *a;
	if (size <= 5)
		return (small_sort(a, b));
	counter = 0;
	mid = size / 2 - 1;
	if (size <= 40)
	{
		offset = 5;
		end = mid + offset;
		start = mid - offset;
	}
	else if (size <= 100)
	{
		offset = 15;
		end = mid + offset;
		start = mid - offset;
	}
	else if (size <= 500)
	{
		offset = 100;
		end = mid + offset;
		start = mid - offset;
	}
	else
	{
		offset = 80;
		end = mid + offset;
		start = mid - offset;
	}
	numsort(nums, size);
	while (*a)
	{
		// if inside the range push to b
		if ((*a)->number >= nums[start] && (*a)->number <= nums[end])
		{
			pb(a, b);
			// if the number is bigger than the mid of the range rotate b
			if (ft_stacksize(*b) > 1 && (*b)->number < nums[mid])
				rb(b);
		}
		// if the number is not in the range
		else
		{
			// check if a number with the same range is even in a
			tmp = *a;
			while (tmp && (tmp->number < nums[start] || tmp->number > nums[end]))
			{
				counter++;
				tmp = tmp->next;
			}
			// if not, increase the range, and reset the counter
			if (counter == ft_stacksize(*a))
			{
				if ((end + counter) / offset < size)
					end += offset;
				else
					end = size - 1;
				if (start - counter >= 0)
					start -= offset;
				else
					start = 0;
				counter = 0;
			}
			// if the number is in the first half of the range, better to rotate a
			else
			{
				if (counter < ft_stacksize(*a) / 2)
					while (counter)
					{
						ra(a);
						counter--;
					}
				// if the number is in the second half of the range, better to reverse rotate a
				else
				{
					counter = ft_stacksize(*a) - counter;
					while (counter)
					{
						rra(a);
						counter--;
					}
				}
			}
		}

	}
	while(*b)
	{
		if ((*b)->number == nums[size - 1])
		{
			pa(a, b);
			size--;
		}
		else if ((*b)->next && (*b)->next->number == nums[size - 1])
			sb(b);
		else
		{
			rotate_b_to_max(b, nums, size - 1);
			pa(a, b);
			size--;
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

