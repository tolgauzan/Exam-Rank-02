/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:09:10 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/14 01:09:10 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static int	is_space_tab_nl(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static void	**ft_free(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
}

static size_t	word_len(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && !is_space_tab_nl(s[len]))
		len++;
	return (len);
}

static size_t	word_count(char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (is_space_tab_nl(*s))
			s++;
		else
		{
			count++;
			s += word_len(s);
		}
	}
	return (count);
}

char	**ft_split(char *str)
{
	char	**list;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!str)
		return (NULL);
	list = (char **)malloc((word_count(str) + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (is_space_tab_nl(*str))
			str++;
		else
		{
			len = word_len(str);
			list[i] = (char *)malloc((len + 1) * sizeof(char));
			if (!list[i])
				return (ft_free(list), NULL);
			j = 0;
			while (j < len)
				list[i][j++] = *str++;
			list[i][len] = '\0';
			i++;
		}
	}
	list[i] = NULL;
	return (list);
}

int	main(int ac, char **av)
{
	char	**list;
	size_t	count;

	if (ac == 2)
	{
		list = ft_split(av[1]);
		if (!list)
			return (1);
		count = 0;
		while (list[count])
			count++;
		while (count > 0)
		{
			count--;
			write(STDOUT_FILENO, list[count], word_len(list[count]));
			if (count > 0)
				write(STDOUT_FILENO, " ", 1);
		}
		ft_free(list);
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}