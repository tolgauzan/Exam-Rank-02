/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:10:22 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/09 19:10:22 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	alpha_mirror(char *s)
{
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s = ('z' - *s) + 'a';
		else if (*s >= 'A' && *s <= 'Z')
			*s = ('Z' - *s) + 'A';
		write(STDOUT_FILENO, s++, 1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		alpha_mirror(av[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
