/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:01:47 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/13 21:01:47 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	is_space_tab_end(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

static int	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

static int	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

static void	rstr_capitalizer(char *s)
{
	while (*s)
	{
		*s = to_lower(*s);
		if (*s >= 'a' && *s <= 'z' && is_space_tab_end(*(s + 1)))
			*s = to_upper(*s);
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
			rstr_capitalizer(av[i]);
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
	}
	return (0);
}