/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:15:01 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/09 18:15:01 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_num(unsigned short nb)
{
	if (nb >= 10)
		print_num(nb / 10);
	write(STDOUT_FILENO, &"0123456789"[nb % 10], 1);
}

static void	fizzbuzz(unsigned short min, unsigned short max)
{
	while (min <= max)
	{
		if (min % 3 == 0 && min % 5 == 0)
			write(STDOUT_FILENO, "fizzbuzz", 8);
		else if (min % 3 == 0)
			write(STDOUT_FILENO, "fizz", 4);
		else if (min % 5 == 0)
			write(STDOUT_FILENO, "buzz", 4);
		else
			print_num(min);
		write(STDOUT_FILENO, "\n", 1);
		min++;
	}
}

int	main(void)
{
	unsigned short	min;
	unsigned short	max;

	min = 1;
	max = 100;
	fizzbuzz(min, max);
	return (0);
}
