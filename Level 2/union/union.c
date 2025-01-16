/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:30:39 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/09 20:30:39 by tuzan            ###   ########.fr       */
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

static void	ft_union(char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		if (not_seen_before(s1, s1[i], i))
		{
			write(STDOUT_FILENO, &s1[i], 1);
		}
		i++;
	}
	j = 0;
	while (s2[j])
	{
		if (not_seen_before(s1, s2[j], i) && not_seen_before(s2, s2[j], j))
		{
			write(STDOUT_FILENO, &s2[j], 1);
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}