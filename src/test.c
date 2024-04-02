// #include "../includes/push_swap.h"

// int main() {
//     // Create two new stacks
//     t_stack *stack1 = ft_stacknew(0, 5);
//     t_stack *stack2 = NULL;
//     if (!stack1) {
//         printf("Failed to create stack1\n");
//         return 1;
//     }

//     // Add some elements to stack1
//     for (int i = 1; i < 5; i++) {
//         t_stack *new_node = ft_stacknew(i, i * 10);
//         if (!new_node) {
//             printf("Failed to create stack node\n");
//             ft_stackclear(&stack1);
//             return 1;
//         }
//         ft_stackadd_front(&stack1, new_node);
//     }

//     // Print stack1
//     printf("Stack1 before:\n");
//     t_stack *ptr = stack1;
//     while (ptr) {
//         printf("Index: %d, Number: %d\n", ptr->index, ptr->number);
//         ptr = ptr->next;
//     }

//     // Push elements from stack1 to stack2
//     // for (int i = 0; i < 3; i++) {
//     //     ft_push(&stack1, &stack2);
//     // }
//     // ft_swap(&stack1);
//     ft_reverse_rotate(&stack1);
    
//     // Print stack1 and stack2 after pushing
//     printf("Stack1 after:\n");
//     ptr = stack1;
//     while (ptr) {
//         printf("Index: %d, Number: %d\n", ptr->index, ptr->number);
//         ptr = ptr->next;
//     }

//     ptr = stack2;
//     while (ptr) {
//         printf("Index: %d, Number: %d\n", ptr->index, ptr->number);
//         ptr = ptr->next;
//     }

//     // Clear the stacks
//     ft_stackclear(&stack1);
//     ft_stackclear(&stack2);

//     return 0;
// }