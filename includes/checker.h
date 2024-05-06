/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:06:03 by amouhand          #+#    #+#             */
/*   Updated: 2024/05/05 18:29:48 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int		ft_strcmp(const char *s1, const char *s2);
int		read_instructions(t_stack **a, t_stack **b, char *line);
int		sorted(t_stack **a, t_stack **b);
int		ft_failure(char **s, t_stack **a, t_stack **b, int *nums);
int		reading_lines(t_stack **a, t_stack **b);

#endif
