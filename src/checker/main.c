/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:05:28 by amouhand          #+#    #+#             */
/*   Updated: 2024/05/04 20:06:33 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	main(int ac, char *av[])
{
	t_stack	**a;
	t_stack	**b;
	int		*nums;
	char	**s;

	a = malloc(sizeof(t_stack *));
	b = malloc(sizeof(t_stack *));
	s = parsing(av + 1, ac - 1, &nums);
	if (!s || nillcheck(av + 1, ac - 1))
		exiting(s, a, b, nums);
	init_stacks(a, b, nums, countsplit(s));
	if (!sorted(a, b))
	{
		write(1, "OK\n", 3);
		ft_success(s, a, b, nums);
	}
	if (read_instructions(a, b))
		exiting(s, a, b, nums);
	if (!sorted(a, b))
	{
		write(1, "OK\n", 3);
		ft_success(s, a, b, nums);
	}
	else
		ft_failure(s, a, b, nums);
}
