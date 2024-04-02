/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:20:48 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/02 03:16:01 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
int init_stacks(t_stack **a, t_stack **b, int* nums, int n)
{
	int i;

	i = 0;
	a = (t_stack **)malloc(sizeof(t_stack *));
	b = (t_stack **)malloc(sizeof(t_stack *));
	if (!a || !b)
		return (1);
	while (i < n)
	{
		ft_stackadd_front(a, ft_stacknew(i, nums[i]));
		i++;
	}
	return (0);
}
