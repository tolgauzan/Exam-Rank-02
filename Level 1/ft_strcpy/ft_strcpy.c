/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:23:19 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/09 18:23:19 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *s1, char *s2)
{
	char	*dest;

	dest = s1;
	while (*s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s2 = "Hello";
	char	s1[10];

	printf("%s", ft_strcpy(s1, s2));
	return (0);
}
*/