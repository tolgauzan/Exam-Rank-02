/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:30 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/13 19:10:30 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_num(int num)
{
	if (num >= 10)
		print_num(num / 10);
	write(STDOUT_FILENO, &"0123456789"[num % 10], 1);
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

static void	tab_mult(char *s)
{
	int	num;
	int	i;

	num = atoi_low(s);
	if (num > 0)
	{
		i = 1;
		while (i < 10)
		{
			print_num(i);
			write(STDOUT_FILENO, " x ", 3);
			print_num(num);
			write(STDOUT_FILENO, " = ", 3);
			print_num(i * num);
			if (i < 9)
				write(STDOUT_FILENO, "\n", 1);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		tab_mult(av[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
