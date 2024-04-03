/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 07:08:58 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/03 07:09:29 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}
void	rb(t_stack **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}
void	rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
void	rra(t_stack **a)
{
	ft_reverse_rotate(a);
	write(1, "rra\n", 4);
}
void	rrb(t_stack **b)
{
	ft_reverse_rotate(b);
	write(1, "rrb\n", 4);
}