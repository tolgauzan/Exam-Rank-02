/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:00:03 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/13 22:00:03 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(const char *str, int str_base)
{
	int	num;
	int	sign;
	int	value;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			value = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			value = *str + 10 - 'a';
		else if (*str >= 'A' && *str <= 'F')
			value = *str + 10 - 'A';
		else
			return (0);
		if (value >= str_base)
			return (0);
		num = num * str_base + value;
		str++;
	}
	return (num * sign);
}
