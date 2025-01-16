/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:09:51 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/13 22:09:51 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static void fprime(int num)
{
	int	prime;

	prime = 2;
	if (num == 1)
	{
		printf("1");
		return ;
	}
	while (prime <= num)
	{
		if (num % prime == 0)
		{
			printf("%d", prime);
			if (num != prime)
				printf("*");
			num = num / prime;
		}
		else
			prime++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
