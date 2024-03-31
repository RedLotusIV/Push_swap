/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:17:55 by amouhand          #+#    #+#             */
/*   Updated: 2024/03/31 05:25:09 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int main(int ac, char *av[])
// {
// 	t_tree *tree;

// 	tree = (t_tree *)malloc(sizeof(t_tree));
// 	if (!tree)
// 		exiting("ERROR : Memory allocation failed\n", tree);
// 	if (parsing(av, ac))
// 		exiting("ERROR : Invalid arguments\n", tree);
// 	if (!string_to_array(av, ac, tree->nums))
// 		exiting("ERROR : Memory allocation failed\n", tree);
// 	if (ac == 2 || !is_sorted(tree->nums, ac - 1))
// 		return (0);
// 	radixsort(tree->nums, sizeof(&tree->nums) / sizeof(tree->nums[0]));
// 	for(int i = 0; i < ac; i++)
// 		printf("%d\n", tree->nums[i]);
// 	return (0);
// }