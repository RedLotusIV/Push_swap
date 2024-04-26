/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:39:09 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/05 16:39:47 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
int	get_max(t_stack **stack)
{
	t_stack	*tmp;
	int		max;
	int		index;

	index = 0;
	tmp = *stack;
	max = tmp->number;
	while (tmp)
	{
		if (max < tmp->number)
		{
			max = tmp->number;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index);
}