/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:05:55 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/02 03:49:41 by amouhand         ###   ########.fr       */
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
}				t_stack;

void		exiting(char *msg, t_stack **a, t_stack **b, int *nums);
char		**parsing(char **command, int number, int *nums);
int			error_check(char *num);
long long	ft_atol(const char *nptr);
void		*delete(void *content);
void		countSort(int arr[], int n, int exp);
int			is_sorted(int arr[], int size);
int			string_to_array(char **chars, int n, int **nums);
int			is_sorted(int arr[], int size);
int			find_duplicates(char **numbers, int n);
void		radixsort(int arr[], int n);
int			getMax(int arr[], int n);
t_stack		*ft_stacklast(t_stack *stack);
t_stack		*ft_stacknew(int index, int number);
void		ft_stackadd_front(t_stack **stack, t_stack *new);
void		ft_stackclear(t_stack **stack);
void		ft_stackdelone(t_stack *stack);
int			ft_swap(t_stack **stack);
int			ft_push(t_stack **from, t_stack **to);
int			ft_rotate(t_stack **stack);
int			ft_reverse_rotate(t_stack **stack);
int			init_stacks(t_stack **a, t_stack **b, int *nums, int n);
char		*splitting(char *s, char *str);
int			countsplit(char **split);
#endif