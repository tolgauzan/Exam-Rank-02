/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:20:28 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/13 19:20:28 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_hex(int num)
{
	if (num > 15)
		print_hex(num / 16);
	write(STDOUT_FILENO, &"0123456789abcdef"[num % 16], 1);
}

static int	atoi_low(char *s)
{
	int	num;

	num = 0;
	while (*s >= '0' && *s <= '9')
	{
		num = (num * 10) + (*s - '0');
		s++;
	}
	return (num);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		print_hex(atoi_low(av[1]));
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
