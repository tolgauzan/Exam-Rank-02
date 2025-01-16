/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:09:57 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/09 20:09:57 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

static int	not_seen_before(char *s, char c, size_t max_pos)
{
	size_t	i;

	i = 0;
	while (i < max_pos)
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

static void	inter(char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				if (not_seen_before(s1, s1[i], i))
				{
					write(STDOUT_FILENO, &s1[i], 1);
					break;
				}
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}