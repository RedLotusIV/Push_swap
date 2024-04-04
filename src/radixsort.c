/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 07:48:58 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/04 02:12:53 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// function radixsort(a, b)
//   max_val = find_max(a)
//   num_digits = count_digits(max_val)

//   for i from 0 to num_digits-1
//     counting_sort(a, b, i)
//   end for
// end function

// function counting_sort(a, b, digit)
//   // Use the operations to sort based on the digit
//   for each number in a
//     digit_val = get_digit(number, digit)
//     if digit_val is 0
//       pb(a, b) // push to b if digit is 0
//     else
//       ra(a) // rotate a if digit is 1
//     end if
//   end for

//   // Move all elements back to a
//   while b is not empty
//     pa(a, b)
//   end while
// end function