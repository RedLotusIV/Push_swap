/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 06:56:09 by amouhand          #+#    #+#             */
/*   Updated: 2024/05/06 23:00:35 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	nillcheck(char **av, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '\0')
			return (1);
		while (av[i][j])
		{
			minus_space(av[i], &j);
			if (av[i][j] == '-' || av[i][j] == '+')
			{
				if (!ft_isdigit(av[i][++j]))
					return (1);
			}
			if (!ft_isdigit(av[i][j]) && !(av[i][j] == ' '))
				return (1);
			j++;
			minus_space(av[i], &j);
		}
		i++;
	}
	return (0);
}

void	minus_space(char *s, int *i)
{
	while (s[*i] == ' ')
		(*i)++;
}

long long	ft_atol(const char *nptr, int *over_int)
{
	long		sign;
	long long	outcome;
	size_t		i;

	sign = 1;
	i = space_skip((char *)nptr, &sign);
	outcome = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		outcome = outcome * 10 + nptr[i] - '0';
		if (outcome > INT_MAX || outcome < INT_MIN)
			(*over_int)++;
		i++;
	}
	return ((outcome * sign));
}

int	space_skip(char *nptr, long *sign)
{
	int	i;

	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			(*sign) *= -1;
		i++;
	}
	return (i);
}
