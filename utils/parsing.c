/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:40:52 by amouhand          #+#    #+#             */
/*   Updated: 2024/03/21 12:49:27 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int parsing(char **command, int n)
{
	int i;

	i = 1;
	while (n > i)
	{
		if (error_check(command[i]))
			return (1);
		if (find_duplicates(command, n))
			return (1);
		i++;
	}
	return (0);
}
int error_check(char *num)
{
	int i;
	long long number;
	i = 0;

	number = ft_atol(num);
	if (number > INT_MAX || number < INT_MIN)
		return (1);
	if (num[i] == '+' || num[i] == '-')
		i++;
	while(num[i])
	{
		if (!ft_isdigit(num[i]))
        	return 1;	
		i++;
	}
	return (0);
}
int find_duplicates(char **numbers, int n)
{
	int i;
	int j;
	int arr[n];
	
	i = 0;
	j = 0;
	string_to_array(numbers, n, arr);
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}