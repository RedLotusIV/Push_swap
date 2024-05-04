/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:06:03 by amouhand          #+#    #+#             */
/*   Updated: 2024/05/04 19:48:49 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int		ft_strcmp(const char *s1, const char *s2);
int		read_instructions(t_stack **a, t_stack **b);
int		continue_reading(char *line, t_stack **a, t_stack **b);
int		sorted(t_stack **a, t_stack **b);
int		ft_failure(char **s, t_stack **a, t_stack **b, int *nums);

#endif
