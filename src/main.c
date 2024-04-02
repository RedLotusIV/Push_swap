/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:17:55 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/02 03:44:40 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char *av[])
{
	t_stack **a;
	t_stack **b;
	int		*nums;
	char **s;

	a = NULL;
	b = NULL;
	nums = NULL;
	s = parsing(av + 1, ac - 1, nums);
	if (!s)
		exiting("ERROR : Invalid arguments\n", a, b, nums);
	if (!is_sorted(nums, ac - 1))
		return (0);
	init_stacks(a, b, nums, countsplit(s));
	return (0);
}