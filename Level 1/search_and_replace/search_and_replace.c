/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:58:13 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/09 18:58:13 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	search_and_replace(char *s, char *search, char *replace)
{
	while (*s)
	{
		if (*s == *search)
			*s = *replace;
		write(STDOUT_FILENO, s++, 1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		if (av[2][1] == '\0' && av[3][1] == '\0')
			search_and_replace(av[1], &av[2][0], &av[3][0]);
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
