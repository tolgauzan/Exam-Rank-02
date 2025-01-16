/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:04:09 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/09 18:04:09 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	is_space_tab(char c)
{
	return (c == ' ' || c == '\t');
}

static void	first_word(char *s)
{
	while (*s && is_space_tab(*s))
		s++;
	while (*s && !is_space_tab(*s))
		write(STDOUT_FILENO, s++, 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		first_word(av[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
