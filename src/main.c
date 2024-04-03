/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:17:55 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/03 08:28:59 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char *av[])
{
	t_stack **a;
	t_stack **b;
	int		*nums;
	char **s;

	a = malloc(sizeof(t_stack *));
	b = malloc(sizeof(t_stack *));
	nums = NULL;

	s = parsing(av + 1, ac - 1, &nums);
	if (!s || nillcheck(av + 1, ac - 1))
		exiting(s, a, b, nums);
	if (is_sorted(nums, countsplit(s)))
		ft_success(s, a, b, nums);
	init_stacks(a, b, nums, countsplit(s));
	ft_success(s, a, b, nums);
	return (0);
}