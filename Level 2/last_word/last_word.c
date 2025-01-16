/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:26:05 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/09 21:26:05 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

static int	is_space_tab(char c)
{
	return (c == ' ' || c == '\t');
}

static void	last_word(char *s)
{
	size_t i;
	size_t end;

	i = 0;
	end = 0;
	while (s[i])
	{
		if (!is_space_tab(s[i]))
			end = i;
		i++;
	}
	if (end == 0 && s[0] == '\0')
		return ;
	while (end > 0 && !is_space_tab(s[end - 1]))
		end--;
	while (s[end] && !is_space_tab(s[end]))
	{
        write(STDOUT_FILENO, &s[end], 1);
        end++;
    }
}

int	main(int ac, char **av)
{
	if (ac == 2)
		last_word(av[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}