/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:40:52 by amouhand          #+#    #+#             */
/*   Updated: 2024/05/05 15:51:12 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**parsing(char **command, int n, int **nums)
{
	int		i;
	char	*string;
	char	**split;

	i = 0;
	string = ft_strdup("");
	while (n > i)
	{
		string = splitting(string, command[i]);
		if (!string)
			return (NULL);
		i++;
	}
	split = ft_split(string, ' ');
	if (!(duplicates_and_errors(split, nums, string)))
		return (NULL);
	free(string);
	return (split);
}

char	**duplicates_and_errors(char **split, int **nums, char *string)
{
	int	i;
	int	j;

	i = 0;
	j = countsplit(split);
	if (find_duplicates(split, j))
	{
		free(*nums);
		free_all(split, j);
		free(string);
		return (NULL);
	}
	string_to_array(split, j, nums);
	while (j > i)
	{
		if (error_check(split[i]))
		{
			free_all(split, j);
			free(string);
			return (NULL);
		}
		i++;
	}
	return (split); //-203487230472304734 -1 0 23
}

int	error_check(char *num)
{
	int			i;
	long long	number;
	int over_int;

	i = 0;
	over_int = 0;
	if (num == NULL || num[0] == '\0')
		return (1);
	number = ft_atol(num, &over_int);
	if (number < -2147483648 || over_int)
		return (1);
	if (num[i] == '+' || num[i] == '-')
		i++;
	if (num[i] == '\0')
		return (1);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (1);
		i++;
	}
	return (0);
}

int	find_duplicates(char **numbers, int n)
{
	int	i;
	int	j;
	int	*arr;

	i = 0;
	j = 0;
	string_to_array(numbers, n, &arr);
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
			{
				free(arr);
				return (1);
			}
			j++;
		}
		i++;
	}
	free(arr);
	return (0);
}

void	free_all(char **strs, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (strs[i])
			free(strs[i]);
		i++;
	}
	free(strs);
}
