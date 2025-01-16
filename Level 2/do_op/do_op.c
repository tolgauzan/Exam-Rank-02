/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:21:02 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/09 19:21:02 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static void	do_op(int val1, int val2, char opr)
{
	if (opr == '+')
		printf("%d", val1 + val2);
	else if (opr == '-')
		printf("%d", val1 - val2);
	else if (opr == '*')
		printf("%d", val1 * val2);
	else if (opr == '/')
	{
		if (val2 != 0)
			printf("%d", val1 / val2);
	}
	else if (opr == '%')
	{
		if (val2 != 0)
			printf("%d", val1 % val2);
	}
}

int	main(int ac, char **av)
{
	int		val1;
	int		val2;
	char	opr;

	if (ac == 4)
	{
		if (av[2][1] == '\0')
		{
			val1 = atoi(av[1]);
			val2 = atoi(av[3]);
			opr = av[2][0];
			do_op(val1, val2, opr);
		}
	}
	printf("\n");
	return (0);
}
