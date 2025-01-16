/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:28:26 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/14 01:28:26 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				temp;

	if (!tab || size <= 1)
		return ;
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}
/*
#include <stdio.h>
void	print_array(int *tab, unsigned int size)
{
	unsigned int i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", tab[i]);
	}
	printf("\n");
}

int	main(void)
{
	int arr1[] = {5, 3, 9, 1, 6};
	unsigned int size1 = sizeof(arr1) / sizeof(arr1[0]);
	printf("Original Array 1: ");
	print_array(arr1, size1);
	sort_int_tab(arr1, size1);
	printf("Sorted Array 1:   ");
	print_array(arr1, size1);
	
	int arr2[] = {10, 2, 7, 8, 4};
	unsigned int size2 = sizeof(arr2) / sizeof(arr2[0]);
	printf("Original Array 2: ");
	print_array(arr2, size2);
	sort_int_tab(arr2, size2);
	printf("Sorted Array 2:   ");
	print_array(arr2, size2);
	
	int arr3[] = {1, 2, 3, 4, 5};
	unsigned int size3 = sizeof(arr3) / sizeof(arr3[0]);
	printf("Original Array 3: ");
	print_array(arr3, size3);
	sort_int_tab(arr3, size3);
	printf("Sorted Array 3:   ");
	print_array(arr3, size3);
	
	int arr4[] = {1, 1, 1, 1, 1};
	unsigned int size4 = sizeof(arr4) / sizeof(arr4[0]);
	printf("Original Array 4: ");
	print_array(arr4, size4);
	sort_int_tab(arr4, size4);
	printf("Sorted Array 4:   ");
	print_array(arr4, size4);
	
	return 0;
}
*/