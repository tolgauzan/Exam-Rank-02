/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:44:25 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/14 00:44:25 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	is_space_tab(char c)
{
	return (c == ' ' || c == '\t');
}

static void	write_word(char *str, int start, int end)
{
	while (start < end)
		write(STDOUT_FILENO, &str[start++], 1);
}

static void	rev_wstr(char *str)
{
	int	len;
	int	end;

	len = 0;
	while (str[len])
		len++;
	end = len;
	while (len > 0)
	{
		len--;
		if (is_space_tab(str[len]) || len == 0)
		{
			if (!is_space_tab(str[len]))
				len--;
			write_word(str, len + 1, end);
			if (len > 0)
				write(STDOUT_FILENO, " ", 1);
			end = len;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}