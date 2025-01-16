/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:32:21 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/13 19:32:21 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	is_space_tab(char c)
{
	return (c == ' ' || c == '\t');
}

static void	epur_str(char *s)
{
	while (is_space_tab(*s))
		s++;
	while (*s)
	{
		if (!is_space_tab(*s))
			write(STDOUT_FILENO, s, 1);
		else if (is_space_tab(*s))
		{
			if (!is_space_tab(*(s + 1)) && (*(s + 1)) != '\0')
				write(STDOUT_FILENO, " ", 1);
		}
		s++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		epur_str(av[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
