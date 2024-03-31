/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:05:55 by amouhand          #+#    #+#             */
/*   Updated: 2024/03/31 06:18:12 by amouhand         ###   ########.fr       */
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

typedef struct s_tree
{
	char			*args;
	int 			*nums;
	struct s_stack	*a;
	struct s_stack	*b;
}				t_tree;

void		exiting(char *msg, t_tree *tree);
int			parsing(char **command, int number);
int			error_check(char *num);
long long	ft_atol(const char *nptr);
void		*delete(void *content);
void		countSort(int arr[], int n, int exp);
int			is_sorted(int arr[], int size);
int			*string_to_array(char **chars, int n, int *nums);
int			is_sorted(int arr[], int size);
int			find_duplicates(char **numbers, int n);
void		radixsort(int arr[], int n);
int			getMax(int arr[], int n);
t_stack		*ft_stacklast(t_stack *stack);
t_stack		*ft_stacknew(int index, int number);
void		ft_stackadd_front(t_stack **stack, t_stack *new);
void		ft_stackclear(t_stack **stack);
void		ft_stackdelone(t_stack *stack);
void		swap(t_stack **stack);

#endif