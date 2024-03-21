// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   structs.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/03/20 11:08:35 by amouhand          #+#    #+#             */
// /*   Updated: 2024/03/20 11:32:04 by amouhand         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/push_swap.h"

// t_stack	*ft_stackmap(t_stack *stack, void (*delete)(void *))
// {
// 	t_stack	*ptr;
// 	t_stack	*new;

// 	if (!delete || !stack)
// 		return (0);
// 	new = NULL;
// 	while (stack)
// 	{
// 		// ptr = ft_stacknew(int index, int value);
// 		ft_stackadd_back(&new, ptr);
// 		if (!ptr)
// 		{
// 			ft_stackclear(&new, delete);
// 			return (0);
// 		}
// 		stack = stack->next;
// 	}
// 	return (new);
// }
// t_stack	*ft_stacknew(int index, int number)
// {
// 	t_stack	*head;

// 	head = NULL;
// 	head = (t_stack *)malloc(sizeof(*head));
// 	if (head == NULL)
// 		return (NULL);
// 	head -> index = index;
// 	head -> number = number;
// 	head -> next = NULL;
// 	return (head);
// }
// void	ft_stackadd_back(t_stack **stack, t_stack *new)
// {
// 	t_stack	*last_node;

// 	if (!stack || !new)
// 		return ;
// 	if (*stack)
// 	{
// 		last_node = ft_stacklast(*stack);
// 		last_node->next = new;
// 	}
// 	else
// 	{
// 		*stack = new;
// 	}
// }
// void	ft_stackclear(t_stack **stack, void (*delete)(void*))
// {
// 	t_stack	*ptr;
// 	t_stack	*store;

// 	if (!stack || !delete)
// 		return ;
// 	ptr = *stack;
// 	store = NULL;
// 	while (ptr)
// 	{
// 		store = ptr->next;
// 		ft_stackdelone(ptr, delete);
// 		ptr = store;
// 	}
// 	*stack = NULL;
// }
// void	ft_stackdelone(t_stack *stack, void (*delete)(void*))
// {
// 	if (stack)
// 	{
// 		delete(stack->number);
// 		delete(stack->index);
// 		free(stack);
// 	}
// }
