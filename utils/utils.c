/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:02:17 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/28 11:26:52 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_over(unsigned long int i)
{
	if (i > INT_MAX)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (0);
}

void	exiting(char **split, t_stack **a, t_stack **b, int *nums)
{
	write(2, "Error\n", 6);
	if (a)
		free(a);
	if (b)
		free(b);
	if (nums)
		free(nums);
	if (split)
		free_all(split, countsplit(split));
	exit(1);
}

void	ft_success(char **split, t_stack **a, t_stack **b, int *nums)
{
	if (a)
	{
		if (*a)
			ft_stackclear(a);
		free(a);
	}
	if (b)
	{
		if (*b)
			ft_stackclear(b);
		free(b);
	}
	if (nums)
		free(nums);
	if (split)
		free_all(split, countsplit(split));
	exit(0);
}

int	is_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	string_to_array(char **chars, int n, int **nums)
{
	int	i;

	i = 0;
	*nums = (int *)malloc(sizeof(int) * n);
	if (!*nums)
		return (1);
	while (i < n)
	{
		nums[0][i] = ft_atoi(chars[i]);
		i++;
	}
	return (0);
}
