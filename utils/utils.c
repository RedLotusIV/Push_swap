/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:02:17 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/03 07:56:57 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void exiting(char **split, t_stack **a, t_stack **b, int *nums)
{
	int i;

	i = 0;
	write(2, "Error\n", 6);
	if (a)
	{
		ft_stackclear(a);
		free(a);
	}
	if (b)
	{
		ft_stackclear(b);
		free(b);
	}
	if (nums)
		free(nums);
	if (split)
		free_all(split, countsplit(split));
	exit(1);
}
void ft_success(char **split, t_stack **a, t_stack **b, int *nums)
{
	if (a)
	{
		ft_stackclear(a);
		free(a);
	}
	if (b)
	{
		ft_stackclear(b);
		free(b);
	}
	if (nums)
		free(nums);
	if (split)
		free_all(split, countsplit(split));
	exit(0);
}

long	long	ft_atol(const char *nptr)
{
	long		sign;
	long long	outcome;
	size_t	i;

	i = 0;
	outcome = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		outcome = outcome * 10 + nptr[i] - '0';
		i++;
	}
	return ((outcome * sign));
}
int is_sorted(int *arr, int size)
{
	int i;

	i = 0;
    while(i < size)
	{
        if (arr[i] > arr[i + 1])
            return (1);
		i++;
    }
    return (0);
}

int string_to_array(char **chars, int n, int **nums)
{
	int i;

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