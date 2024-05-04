/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:30:32 by amouhand          #+#    #+#             */
/*   Updated: 2024/05/04 20:14:23 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	read_instructions(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!ft_strcmp(line, "sa\n"))
			ft_swap(a);
		else if (!ft_strcmp(line, "sb\n"))
			ft_swap(b);
		else if (!ft_strcmp(line, "ss\n"))
		{
			ft_swap(a);
			ft_swap(b);
		}
		else if (!ft_strcmp(line, "pa\n"))
			ft_push(a, b);
		else
		{
			if (continue_reading(line, a, b))
				return (free(line), 1);
		}
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

int	continue_reading(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "pb\n"))
		ft_push(b, a);
	else if (!ft_strcmp(line, "ra\n"))
		ft_rotate(a);
	else if (!ft_strcmp(line, "rb\n"))
		ft_rotate(b);
	else if (!ft_strcmp(line, "rr\n"))
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	else if (!ft_strcmp(line, "rra\n"))
		ft_reverse_rotate(a);
	else if (!ft_strcmp(line, "rrb\n"))
		ft_reverse_rotate(b);
	else if (!ft_strcmp(line, "rrr\n"))
	{
		ft_reverse_rotate(a);
		ft_reverse_rotate(b);
	}
	else
		return (1);
	return (0);
}

int	sorted(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	while (temp->next)
	{
		if (temp->number > temp->next->number)
			return (1);
		temp = temp->next;
	}
	if (*b)
		return (1);
	return (0);
}

int	ft_failure(char **s, t_stack **a, t_stack **b, int *nums)
{
	if (a)
	{
		if (*a)
			ft_stackclear(a);
		free(a);
	}
	if (b)
	{
		if (*b)
			ft_stackclear(b);
		free(b);
	}
	if (nums)
		free(nums);
	if (s)
		free_all(s, countsplit(s));
	write(2, "KO\n", 3);
	exit(0);
}
