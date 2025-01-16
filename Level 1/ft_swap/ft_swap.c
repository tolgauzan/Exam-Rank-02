/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:28:08 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/09 18:28:08 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
#include <stdio.h>
int	main(void)
{
	int	a = 2, b = 4;

	printf("a : %d , b : %d\n", a, b);
	ft_swap(&a, &b);
	printf("a : %d , b : %d\n", a, b);
	return (0);
}
*/