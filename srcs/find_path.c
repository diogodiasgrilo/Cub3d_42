/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:59:27 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/04 11:38:31 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void	find_path(char **map, int x, int y, int *c)
{
	*c += ('E' == map[y][x] || 'C' == map[y][x]);
	map[y][x] = 'R';
	if ('1' != map[y][x + 1] && 'R' != map[y][x + 1])
		find_path(map, x + 1, y, c);
	if ('1' != map[y][x - 1] && 'R' != map[y][x - 1])
		find_path(map, x - 1, y, c);
	if ('1' != map[y + 1][x] && 'R' != map[y + 1][x])
		find_path(map, x, y + 1, c);
	if ('1' != map[y - 1][x] && 'R' != map[y - 1][x])
		find_path(map, x, y - 1, c);
}
