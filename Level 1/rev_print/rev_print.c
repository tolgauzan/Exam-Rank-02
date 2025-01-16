/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:36:50 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/09 18:36:50 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

static void	rev_print(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	while (len > 0)
		write(STDOUT_FILENO, &s[--len], 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_print(av[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}