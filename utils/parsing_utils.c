/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:47:35 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/28 12:39:04 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*join_strings(char *s, char *str)
{
	char	*tmp;

	tmp = ft_strjoin(s, str);
	free(s);
	if (!tmp)
		return (NULL);
	s = tmp;
	tmp = ft_strjoin(s, " ");
	free(s);
	if (!tmp)
		return (NULL);
	s = tmp;
	return (s);
}

char	*splitting(char *s, char *str)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(str, ' ');
	if (!split)
		return (NULL);
	while (split[i])
	{
		s = join_strings(s, split[i]);
		if (!s)
		{
			free_all(split, countsplit(split));
			return (NULL);
		}
		i++;
	}
	free_all(split, i);
	return (s);
}

int	countsplit(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}
