#include "../includes/push_swap.h"
void ft_swap(t_stack **stack)
{
	t_stack *tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = ft_stacknew(0, 0);
	if (!tmp)
		return	;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp->next->next;
	tmp->next->next = *stack;
	*stack = tmp->next;
	free(tmp);
}
void ft_push(t_stack **from, t_stack **to)
{
	t_stack *new_node;
	
    if (!from || !*from || !to)
        return ;
    new_node = ft_stacknew((*from)->index, (*from)->number);
    if (!new_node)
        return;
    ft_stackadd_front(to, new_node);
    t_stack *temp = *from;
    *from = (*from)->next;
    free(temp);
}
// void rotate(t_stack **stack)
// {
// 	t_stack *tmp;
// 	if (!stack || !*stack)
// 		return ;
	
// 	tmp = *stack;
// 	*stack = ft_stacklast(*stack);
// 	while(tmp->next != *stack)
// 	{
// 		tmp->next = ;
// 		tmp = tmp->next;
// 	}
// }
void reverse_rotate(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
}
