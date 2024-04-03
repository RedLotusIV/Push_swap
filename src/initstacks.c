/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:20:48 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/03 08:09:47 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
int init_stacks(t_stack **a, t_stack **b, int* nums, int n)
{
    int i;
    t_stack *node;
    t_stack *tmp;

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
    sa(a);
    tmp = *a;
    printf("stack a\n");
    while (tmp)
    {
        printf("index: %d, number: %d\n", tmp->index, tmp->number);
        tmp = tmp->next;
    }
    pb(a, b);
    pb(a, b);
    tmp = *b;
    printf("stack b\n");
    while (tmp)
    {
        printf("index: %d, number: %d\n", tmp->index, tmp->number);
        tmp = tmp->next;
    }
    tmp = *a;
    printf("stack a\n");
    while (tmp)
    {
        printf("index: %d, number: %d\n", tmp->index, tmp->number);
        tmp = tmp->next;
    }
    return (0);
}
