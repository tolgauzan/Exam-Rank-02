/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:29:14 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/13 22:29:14 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_len(int nbr)
{
	int	count;

	count = (nbr <= 0);
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	long	num;
	int		len;

	num = nbr;
	len = count_len(nbr);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num != 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	int test_cases[] = {0, 123, -123, 1, -1, 42, -42, 2147483647, -2147483648};
	int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	printf("ft_itoa Tests:\n\n");
	for (int i = 0; i < num_tests; i++)
	{
		char *result = ft_itoa(test_cases[i]);
		if (result)
		{
			printf("Input: %d\tOutput: %s\n", test_cases[i], result);
			free(result);
		}
		else
		{
			printf("Input: %d\tOutput: NULL (malloc failed)\n", test_cases[i]);
		}
	}
	return 0;
}
*/
