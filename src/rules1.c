/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 07:06:24 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/03 08:08:50 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}
void sb(t_stack **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}
void ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
void pb(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	write(1, "pb\n", 3);
}
void pa(t_stack **a, t_stack **b)
{
	ft_push(b, a);
	write(1, "pa\n", 3);
}