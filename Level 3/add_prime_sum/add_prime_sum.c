/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:33:42 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/13 21:33:42 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

static int	is_prime(int num)
{
	int	i;

	if (num < 2)
		return (0);
	i = 2;
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

static void	print_num(int num)
{
	if (num > 9)
		print_num(num / 10);
	write(STDOUT_FILENO, &"0123456789"[num % 10], 1);
}

static void	add_prime_sum(char *s)
{
	int	num;
	int	sum;
	int	i;

	num = atoi_low(s);
	sum = 0;
	i = 2;
	while (i <= num)
	{
		if (is_prime(i))
			sum += i;
		i++;
	}
	print_num(sum);
}

int	main(int ac, char **av)
{
	if (ac < 2 || ac > 2)
		write(STDOUT_FILENO, "0", 1);
	else if (ac == 2)
		add_prime_sum(av[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
