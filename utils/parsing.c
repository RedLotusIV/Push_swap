/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:40:52 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/02 03:55:23 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char **parsing(char **command, int n, int *nums)
{
	int i;
	char *string;
	char **split;

	i = 0;
	while (n > i)
	{
		if (error_check(command[i]))
			return (NULL);
		i++;
	}
	i = 0;
	while(n > i)
	{
		string = splitting(string, command[i]);
		if (!string)
			return (NULL);
		i++;
	}
	split = ft_split(string, ' ');
	if (find_duplicates(split, countsplit(split)))
		return (NULL);
	if (string_to_array(split, countsplit(split), &nums))
		return (NULL);
	free(string);
	return (split);
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
	int *arr;
	
	i = 0;
	j = 0;
	string_to_array(numbers, n, &arr);
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
char *splitting(char *s, char *str)
{
	char **split;
	int i;
	
	i = 0;
	split = ft_split(str, ' ');
	if (!split)
		return (NULL);
	while(split[i])
	{
		s = ft_strjoin(s, split[i]);
		s = ft_strjoin(s, " ");
		i++;
	}
	free(split);
	return (s);
}
int	countsplit(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}