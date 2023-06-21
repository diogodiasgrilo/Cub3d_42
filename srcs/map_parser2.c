/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:06:51 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 11:04:22 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

t_map_errors	*init_parser()
{
	t_map_errors *errors;
	
	errors = (t_map_errors *)malloc(sizeof(t_map_errors));
	errors->inv_north = -1;
	errors->inv_south = -1;
	errors->inv_west = -1;
	errors->inv_east = -1;
	errors->inv_floor = -1;
	errors->inv_ceiling = -1;
	errors->north_texture = NULL;
	errors->south_texture = NULL;
	errors->west_texture = NULL;
	errors->east_texture = NULL;
	return (errors);
}

void	inset_file(int *add_direc, char **dest, char*origin)
{
	*add_direc += 1;
	*dest = ft_strdup(origin);
}

int find_color(char *origin, int i, int *grand_total)
{
	int total;

	total = 0;
	while (origin[i])
	{
		while (origin[i] && origin[i] != ',')
		{
			if (!ft_isdigit(origin[i]))
				return (EXIT_FAILURE);
			total *= 10;
			total += origin[i] - 48;
			i++;
		}
		if (total > 255)
			return (EXIT_FAILURE);
		*grand_total *= 256;
		*grand_total += total;
		total = 0;
		if (!origin[i])
			break ;
		i++;
	}
    return (EXIT_SUCCESS);
}

void	inset_color(int *add_color, int *dest, char*origin)
{
	int	i;
	int	grand_total;
	
	i = 0;
	grand_total = 0;
	if (find_color(origin, i, &grand_total) == EXIT_FAILURE)
        return ;
	*add_color += 1;
	*dest = grand_total;
}
