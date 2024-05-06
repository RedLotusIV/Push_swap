/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:05:55 by amouhand          #+#    #+#             */
/*   Updated: 2024/05/06 20:31:04 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}					t_stack;

// Linked Lists
int					init_stacks(t_stack **a, t_stack **b, int *nums, int n);
t_stack				*ft_stacklast(t_stack *stack);
t_stack				*ft_stacknew(int index, int number);
void				ft_stackadd_front(t_stack **stack, t_stack *new);
void				ft_stackclear(t_stack **stack);
void				ft_stackdelone(t_stack *stack);
int					ft_stacksize(t_stack *stack);
void				ft_swap(t_stack **stack);
void				ft_push(t_stack **from, t_stack **to);
void				ft_rotate(t_stack **stack);
void				ft_reverse_rotate(t_stack **stack);
void				*delete(void *content);
// parsing
char				**parsing(char **command, int number, int **nums);
void				exiting(char **split, t_stack **a, t_stack **b, int *nums);
void				ft_success(char **split, t_stack **a, t_stack **b,
						int *nums);
long long			ft_atol(const char *nptr, int *over_int);
int					error_check(char *num);
int					string_to_array(char **chars, int n, int **nums);
int					is_sorted(int *arr, int size);
int					find_duplicates(char **numbers, int n);
int					nillcheck(char **av, int ac);
int					countsplit(char **split);
char				*splitting(char *s, char *str);
void				free_all(char **strs, size_t n);
char				**duplicates_and_errors(char **split, int **nums,
						char *string);
int					space_skip(char *nptr, long *sign, int *flag);
void				minus_space(char *s, int *i);

// rules
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// smallsort
int					sort_2(t_stack **a);
int					sort_3(t_stack **a);
int					sort_5(t_stack **a, t_stack **b);
int					sort_4(t_stack **a, t_stack **b);
int					small_sort(t_stack **a, t_stack **b);
void				numsort(int *nums, int n);
// helpers
int					bigsort(t_stack **a, t_stack **b, int *nums);
int					get_distance(t_stack **stack, int index);
int					get_min(t_stack **stack);
int					reset_index(t_stack **a, t_stack **b);
int					struct_is_sorted(t_stack **a);
int					get_max(t_stack **stack);
int					get_max_number(t_stack *stack);
void				rotate_b_to_max(t_stack **b, int *nums, int size);
void				rotate_b_less_than_half(t_stack **b, int *nums, int size,
						int distance);
void				rotate_b_more_than_half(t_stack **b, int distance);
int					calculate_distance(t_stack **b, int max);
void				sort_a(t_stack **a, t_stack **b, int *nums, int end);
void				sort_b(t_stack **a, t_stack **b, int *nums, int size);
int					determine_end(int size);
void				increment_range(int *start, int *end, int size);

#endif
