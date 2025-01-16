/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:40:33 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/14 01:40:33 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		temp;
	t_list 	*start;

	start = lst;
	while (lst && lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			temp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = temp;
			lst = start;
		}
		else
			lst = lst->next;
	}
	return (start);
}