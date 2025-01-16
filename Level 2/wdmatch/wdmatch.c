/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:40:10 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/09 20:40:10 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

static void	wdmatch(char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s2[j] && s1[i] != s2[j])
			j++;
		if (s2[j] == '\0')
			return ;
		i++;
	}
	write(STDOUT_FILENO, s1, i);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		wdmatch(av[1], av[2]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}