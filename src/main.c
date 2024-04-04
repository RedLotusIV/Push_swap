/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:17:55 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/04 04:14:13 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char *av[])
{
	t_stack **a;
	t_stack **b;
	int		*nums;
	char **s;
	t_stack *tmp;

	a = malloc(sizeof(t_stack *));
	b = malloc(sizeof(t_stack *));
	nums = NULL;

	s = parsing(av + 1, ac - 1, &nums);
	if (!s || nillcheck(av + 1, ac - 1))
		exiting(s, a, b, nums);
	if (!is_sorted(nums, countsplit(s)))
		ft_success(s, a, b, nums);
	init_stacks(a, b, nums, countsplit(s));

	// sort the stacks according to the number of elements
	if (countsplit(s) == 2)
		sort_2(a);
	else if (countsplit(s) == 3)
		sort_3(a);
	else if (countsplit(s) == 4)
		sort_4(a, b);
	else if (countsplit(s) == 5)
		sort_5(a, b);
	else
		sort(a, b);
	// print the stacks
	tmp = *a;
    printf("stack a\n");
    while (tmp)
    {
        printf("index: %d, number: %d\n", tmp->index, tmp->number);
        tmp = tmp->next;
    }
    tmp = *b;
    printf("stack b\n");
    while (tmp)
    {
        printf("index: %d, number: %d\n", tmp->index, tmp->number);
        tmp = tmp->next;
    }
	// exit with 0 and free all the allocated memory
	ft_success(s, a, b, nums);
	return (0);
}