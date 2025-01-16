/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:03:42 by tuzan             #+#    #+#             */
/*   Updated: 2025/01/16 22:03:42 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	fill(char **tab, t_point size, t_point current, char to_fill)
{
	if ((current.y < 0x0) || (current.x < 0x0) || (current.y >= size.y)
		|| (current.x >= size.x) || tab[current.y][current.x] != to_fill)
		return ;
	tab[current.y][current.x] = 'F';
	fill(tab, size, (t_point){current.x - 0x1, current.y}, to_fill);
	fill(tab, size, (t_point){current.x + 0x1, current.y}, to_fill);
	fill(tab, size, (t_point){current.x, current.y - 0x1}, to_fill);
	fill(tab, size, (t_point){current.x, current.y + 0x1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}