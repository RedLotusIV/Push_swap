/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:30:32 by amouhand          #+#    #+#             */
/*   Updated: 2024/05/06 16:49:41 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (1);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	reading_lines(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (read_instructions(a, b, line))
		{
			free(line);
			get_next_line(-1);
			return (1);
		}
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

int	read_instructions(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		return (ft_swap(a), 0);
	else if (!ft_strcmp(line, "sb\n"))
		return (ft_swap(b), 0);
	else if (!ft_strcmp(line, "ss\n"))
		return (ft_swap(a), ft_swap(b), 0);
	else if (!ft_strcmp(line, "pa\n"))
		return (ft_push(b, a), 0);
	else if (!ft_strcmp(line, "pb\n"))
		return (ft_push(a, b), 0);
	else if (!ft_strcmp(line, "ra\n"))
		return (ft_rotate(a), 0);
	else if (!ft_strcmp(line, "rb\n"))
		return (ft_rotate(b), 0);
	else if (!ft_strcmp(line, "rr\n"))
		return (ft_rotate(a), ft_rotate(b), 0);
	else if (!ft_strcmp(line, "rra\n"))
		return (ft_reverse_rotate(a), 0);
	else if (!ft_strcmp(line, "rrb\n"))
		return (ft_reverse_rotate(b), 0);
	else if (!ft_strcmp(line, "rrr\n"))
		return (ft_reverse_rotate(a), ft_reverse_rotate(b), 0);
	return (1);
}

int	sorted(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*a)
		return (1);
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
