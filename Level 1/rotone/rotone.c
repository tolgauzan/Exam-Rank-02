/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:55:04 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/09 18:55:04 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	rotone(char *s)
{
	while (*s)
	{
		if ((*s >= 'a' && *s <= 'y') || (*s >= 'A' && *s <= 'Y'))
			*s += 1;
		else if (*s == 'z' || *s == 'Z')
			*s -= 25;
		write(STDOUT_FILENO, s++, 1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
