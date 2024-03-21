/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:05:55 by amouhand          #+#    #+#             */
/*   Updated: 2024/03/21 12:49:41 by amouhand         ###   ########.fr       */
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

void		exiting(char *msg);
int			parsing(char **command, int number);
int			error_check(char *num);
long long	ft_atol(const char *nptr);
void		*delete(void *content);
int			*countingsort(int *numbers, int n);
int			is_sorted(int arr[], int size);
int			*string_to_array(char **chars, int n, int nums[]);
int			is_sorted(int arr[], int size);
int			find_duplicates(char **numbers, int n);

#endif