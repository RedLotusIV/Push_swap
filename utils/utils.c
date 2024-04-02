/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:02:17 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/02 03:48:14 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void exiting(char *msg, t_stack **a, t_stack **b, int *nums)
{
	write(2, msg, ft_strlen(msg));
	if (a)
		ft_stackclear(a);
	if (b)
		ft_stackclear(b);
	if (nums)
		free(nums);
	exit(1);
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
int is_sorted(int arr[], int size)
{
    for (int i = 1; i < size - 1; i++)
	{
        if (arr[i] > arr[i + 1])
            return (1);
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
		(*nums)[i] = ft_atoi(chars[i]);
		i++;
	}
	return (0);
}