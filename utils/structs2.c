// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   structs2.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/03/20 11:12:21 by amouhand          #+#    #+#             */
// /*   Updated: 2024/03/29 22:14:38 by amouhand         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
		return (NULL);
	last = stack;
	while (last->next)
	{
		last = last->next;
	}
	return (last);
}
