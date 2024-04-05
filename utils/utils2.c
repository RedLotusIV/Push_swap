/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 06:56:09 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/05 12:19:39 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int nillcheck(char **av, int ac)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while(av[i][j] == ' ')
			j++;
		if(av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (!av[i][j])
			return (1);
		while (av[i][j])
		{
		 	if (!ft_isdigit(av[i][j]) && !(av[i][j] == ' '))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
