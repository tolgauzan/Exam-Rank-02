/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:46:52 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/13 22:46:52 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
/*
#include <stdio.h>
int	main(void)
{
	char	**result;
	size_t	i;

	printf("Test 1: \"  Hello world  42!   \"\n");
	result = ft_split("  Hello world  42!   ");
	if (result)
	{
		i = 0;
		while (result[i])
		{
			printf("Word %zu: %s\n", i + 1, result[i]);
			i++;
		}
		ft_free(result);
	}
	printf("\nTest 2: \"       \"\n");
	result = ft_split("       ");
	if (result)
	{
		i = 0;
		while (result[i])
		{
			printf("Word %zu: %s\n", i + 1, result[i]);
			i++;
		}
		ft_free(result);
	}
	printf("\nTest 3: NULL pointer\n");
	result = ft_split(NULL);
	if (!result)
		printf("Result is NULL as expected.\n");
	printf("\nTest 4: \"test1 test2 test3 test4\"\n");
	result = ft_split("test1 test2 test3 test4");
	if (result)
	{
		i = 0;
		while (result[i])
		{
			printf("Word %zu: %s\n", i + 1, result[i]);
			i++;
		}
		ft_free(result);
	}
	printf("\nTest 5: \"    single_word    \"\n");
	result = ft_split("    single_word    ");
	if (result)
	{
		i = 0;
		while (result[i])
		{
			printf("Word %zu: %s\n", i + 1, result[i]);
			i++;
		}
		ft_free(result);
	}
	printf("\nTest 6: \"hello\\tworld\"\n");
	result = ft_split("hello\tworld");
	if (result)
	{
		i = 0;
		while (result[i])
		{
			printf("Word %zu: %s\n", i + 1, result[i]);
			i++;
		}
		ft_free(result);
	}
	return (0);
}
*/