/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_par_map2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:37:33 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 11:37:53 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void	free_split(char **strs)
{
	int	i;

	i = -1;
	while (strs && strs[++i])
		free(strs[i]);
	if (strs)
		free(strs);
}

int	find_s(char **map, int which)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_strchr("NSWE", map[y][x]))
			{
				if (!which)
					return (y);
				else
					return (x);
			}
		}
	}
	return (1);
}

t_err	ft_newmap_error(void)
{
	t_err	map_err;

	map_err.inv_borders = 0;
	map_err.inv_char = 0;
	map_err.inv_rowlen = 0;
	map_err.inv_n_players = 0;
	return (map_err);
}

int		count_rows(char **map)
{
	int	y;
	int	x;
	
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] == 32)
			x++;
		if (map[y][x] != '1')
			break ;
		y++;
	}	
	return (y);
}