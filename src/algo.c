/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:17:51 by amouhand          #+#    #+#             */
/*   Updated: 2024/03/20 17:27:48 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int radix_sort(t_stack num)
// {
// 	int m;
	
// 	m = get_max(array[], n);
// }

int	get_max(int *array, int n)
{
	int max = array[0];
	for (int i = 1; i < n;i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

int *countingsort(int *array, int n)
{
	int out[n];
	int max;
	
	max = get_max(array, n);
	int count[max + 1];
	for (int i = 0; i <= max; i++)
		count[i] = 0;
		
	for (int i = 0; i < n; i++)
		count[array[i]]++;

	for (int j = 1; j <= max; j++)
        count[j] += count[j - 1];
		
	for (int i = n - 1; i >= 0; i--)
        out[--count[(array[i])]] = array[i];

	for (int i = 0; i < n; i++)
        array[i] = out[i];
	
	return array;
}
