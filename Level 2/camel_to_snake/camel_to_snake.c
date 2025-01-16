/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:13:57 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/09 19:13:57 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

static void	camel_to_snake(char *s)
{
	while (*s)
	{
		if (is_upper(*s))
		{
			write(STDOUT_FILENO, "_", 1);
			*s += 32;
		}
		write(STDOUT_FILENO, s++, 1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		camel_to_snake(av[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
