/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:20:48 by amouhand          #+#    #+#             */
/*   Updated: 2024/05/05 17:50:05 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	init_stacks(t_stack **a, t_stack **b, int *nums, int n)
{
	int		i;
	t_stack	*node;

	i = n - 1;
	*a = NULL;
	*b = NULL;
	while (i >= 0)
	{
		node = ft_stacknew(i, nums[i]);
		if (!node)
			return (1);
		ft_stackadd_front(a, node);
		i--;
	}
	return (0);
}
