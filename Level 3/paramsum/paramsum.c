/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:10:56 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/13 20:10:56 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_num(int num)
{
	if (num > 9)
		print_num(num / 10);
	write(STDOUT_FILENO, &"0123456789"[num % 10], 1);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		write(STDOUT_FILENO, "0", 1);
	else
		print_num(ac - 1);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
