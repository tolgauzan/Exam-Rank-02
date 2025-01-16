/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:15:29 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/13 20:15:29 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	is_space_tab(char c)
{
	return (c == ' ' || c == '\t');
}

static void	str_capitalizer(char *s)
{
	int	is_upper;

	is_upper = 1;
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z' && is_upper)
			*s -= 32;
		else if (*s >= 'A' && *s <= 'Z' && !is_upper)
			*s += 32;
		if (is_space_tab(*s))
			is_upper = 1;
		else
			is_upper = 0;
		write(STDOUT_FILENO, s++, 1);
	}
}

int	main(int ac, char **av)
{
	int	i;

	if (ac < 2)
		write(STDOUT_FILENO, "\n", 1);
	else
	{
		i = 1;
		while (i < ac)
		{
			str_capitalizer(av[i]);
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
	}
	return (0);
}
