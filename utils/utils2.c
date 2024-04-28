/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 06:56:09 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/28 11:38:58 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	nillcheck(char **av, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j] == '-' || av[i][j] == '+')
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

long long	ft_atol(const char *nptr)
{
	long		sign;
	long long	outcome;
	size_t		i;
	int			flag;

	flag = 1;
	i = space_skip((char *)nptr, &sign, &flag);
	outcome = 0;
	sign = 1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		outcome = outcome * 10 + nptr[i] - '0';
		i++;
	}
	if (flag == 1)
		check_over(outcome);
	return ((outcome * sign));
}

int	space_skip(char *nptr, long *sign, int *flag)
{
	int	i;

	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		{
			(*sign) *= -1;
			(*flag) = -1;
		}
		i++;
	}
	return (i);
}
