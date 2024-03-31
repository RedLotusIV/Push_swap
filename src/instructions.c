#include "../includes/push_swap.h"
void swap(t_stack **stack)
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
void rotate(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	
}
void reverse_rotate(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
}
void push(t_stack **stack1, t_stack **stack2)
{
	if (!stack1 || !*stack1 || !*stack2 || !stack2)
		return ;
	
}
