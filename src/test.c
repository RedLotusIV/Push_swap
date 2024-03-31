#include "../includes/push_swap.h"
int main() {
    // Create a new stack
    t_stack *stack = ft_stacknew(0, 5);
    if (!stack) {
        printf("Failed to create stack\n");
        return 1;
    }

    // Add some elements to the stack
    for (int i = 1; i < 5; i++) {
        t_stack *new_node = ft_stacknew(i, i * 10);
        if (!new_node) {
            printf("Failed to create stack node\n");
            ft_stackclear(&stack);
            return 1;
        }
        ft_stackadd_front(&stack, new_node);
    }
    swap(&stack);
    // Print the stack
    t_stack *ptr = stack;
    while (ptr) {
        printf("Index: %d, Number: %d\n", ptr->index, ptr->number);
        ptr = ptr->next;
    }

    // Clear the stack
    ft_stackclear(&stack);

    // Try to print the stack again
    if (!stack) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    return 0;
}