/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:05:07 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/09 19:05:07 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

static int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

static void	ulstr(char *s)
{
	while (*s)
	{
		if (is_upper(*s))
			*s += 32;
		else if (is_lower(*s))
			*s -= 32;
		write(STDOUT_FILENO, s++, 1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ulstr(av[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
