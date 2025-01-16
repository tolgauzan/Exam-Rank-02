/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:01:39 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/09 21:01:39 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

static void	snake_to_camel(char *s)
{
	while (*s)
	{
		if (*s == '_')
		{
			s++;
			if (is_lower(*s))
				*s -= 32;
		}
		write(STDOUT_FILENO, s++, 1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		snake_to_camel(av[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}