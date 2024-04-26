/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:40:52 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/17 22:39:33 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char **parsing(char **command, int n, int **nums)
{
	int i;
	int j;
	char *string;
	char **split; 

	i = 0;
	// 1 2 3 "4 5 6"
	string = ft_strdup("");
	while(n > i)
	{
		string = splitting(string, command[i]);
		if (!string)
			return (NULL);
		i++;
	}
	// "1 2 3 4 5 6"
	split = ft_split(string, ' ');
	// "1" "2" "3" "4" "5" "6"
	j = countsplit(split);
	if (find_duplicates(split, j))
	{
		free(*nums);
		free_all(split, j);
		free(string);
		return (NULL);
	}
	string_to_array(split, j, nums);
	i = 0;
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
	if (num[i] == '\0')
		return (1);
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
char *splitting(char *s, char *str)
{
    char **split;
    int i;
    char *tmp;
    
    i = 0;
    split = ft_split(str, ' ');
    if (!split)
        return (NULL);
    while(split[i])
    {
        tmp = ft_strjoin(s, split[i]);
        if (!tmp)
        {
            free_all(split, countsplit(split));
            free(s);
            return (NULL);
        }
        free(s);
        s = tmp;
        tmp = ft_strjoin(s, " ");
        if (!tmp)
        {
            free_all(split, countsplit(split));
			free(s);
            return (NULL);
        }
        free(s);
        s = tmp;
        i++;
    }
    free_all(split, i);
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
void	free_all(char **strs, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}