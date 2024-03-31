/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:40:52 by amouhand          #+#    #+#             */
/*   Updated: 2024/03/31 00:31:21 by amouhand         ###   ########.fr       */
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

	if (num == NULL || num[0] == '\0')
		return (1);
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
int countwords(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			count++;
			while (str[i] != ' ' && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}
int *splitting(char *str, int countwords(char *str))
{
	int *arr;
	char **split;
	int i;
	int n;

	i = 0;
	n = countwords(str);
	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		return (NULL);
	split = ft_split(str, ' ');
	if (!split)
		return (NULL);
	while (i < n)
	{
		arr[i] = ft_atoi(split[i]);
		i++;
	}
	free(split);
	return (arr);
}