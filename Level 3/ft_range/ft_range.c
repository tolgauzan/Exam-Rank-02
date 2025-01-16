/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:55:37 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/13 19:55:37 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	absolute_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	*ft_range(int start, int end)
{
	int	*arr;
	int	size;
	int	i;

	size = absolute_value(end - start) + 1;
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	if (start >= end)
	{
		while (start >= end)
			arr[i++] = start--; 
	}
	if (start <= end)
	{
		while (start <= end)
			arr[i++] = start++;
	}
	return (arr);
}
/*
#include <stdio.h>
int	*ft_range(int start, int end);

void	print_array(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d", arr[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}

int	main(void)
{
	int *result;
	int size;

	size = 3 - 1 + 1;
	result = ft_range(1, 3);
	if (result)
	{
		printf("Test 1 (1 to 3): ");
		print_array(result, size);
		free(result);
	}

	size = 0 - (-3) + 1;
	result = ft_range(0, -3);
	if (result)
	{
		printf("Test 2 (0 to -3): ");
		print_array(result, size);
		free(result);
	}

	size = 1;
	result = ft_range(5, 5);
	if (result)
	{
		printf("Test 3 (5 to 5): ");
		print_array(result, size);
		free(result);
	}

	size = 10 - 5 + 1;
	result = ft_range(5, 10);
	if (result)
	{
		printf("Test 4 (5 to 10): ");
		print_array(result, size);
		free(result);
	}

	size = 4 - (-2) + 1;
	result = ft_range(-2, 4);
	if (result)
	{
		printf("Test 5 (-2 to 4): ");
		print_array(result, size);
		free(result);
	}
	return (0);
}
*/