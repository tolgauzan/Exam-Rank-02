/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:30:54 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/09 18:30:54 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	get_count(char c)
{
	int	count;

	count = 1;
	if (c >= 'a' && c <= 'z')
		count += c - 'a';
	else if (c >= 'A' && c <= 'Z')
		count += c - 'A';
	return (count);
}

static void	repeat_alpha(char *s)
{
	int	count;

	while (*s)
	{
		count = get_count(*s);
		while (count--)
			write(STDOUT_FILENO, s, 1);
		s++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
