#include "../includes/push_swap.h"
int ft_swap(t_stack **stack)
{
	t_stack *tmp;

	if (!stack || !*stack || !(*stack)->next)
		return (-1);
	tmp = ft_stacknew(0, 0);
	if (!tmp)
		return	(-1);
	tmp->next = (*stack)->next;
	(*stack)->next = tmp->next->next;
	tmp->next->next = *stack;
	*stack = tmp->next;
	free(tmp);
	return (0);
}
int ft_push(t_stack **from, t_stack **to)
{
	t_stack *new_node;
	
    if (!from || !*from || !to)
        return (-1);
    new_node = ft_stacknew((*from)->index, (*from)->number);
    if (!new_node)
        return (-1);
    ft_stackadd_front(to, new_node);
    t_stack *temp = *from;
    *from = (*from)->next;
    free(temp);
	return (0);
}
int ft_rotate(t_stack **stack)
{
	t_stack *head;
	t_stack *last;
	if (!stack || !*stack)
		return (-1);

	head = *stack;
	last = ft_stacklast(*stack);
	*stack = head->next;
	head->next = NULL;
	last->next = head;
	return (0);
}
int ft_reverse_rotate(t_stack **stack)
{
	t_stack *head;
	t_stack *before_last;
	t_stack *last;

	if (!stack || !*stack)
		return (-1);
	before_last = *stack;
	last = ft_stacklast(*stack);
	while(before_last->next != last)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (0);
}
