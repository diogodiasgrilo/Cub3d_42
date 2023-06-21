/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:51:16 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 18:07:51 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void	create_player_rows(t_image_creator *ic, int ratio)
{
	while (ic->x < ratio)
	{
		ic->pix_index = (ic->x * ic->bpp / 8) + (ic->y * ic->size_line);
		*(unsigned int *)(ic->data + ic->pix_index) = NEWWHITE;
		ic->x++;
	}
}

void	*create_player(void *mlx)
{
	t_image_creator	ic;

	ic.y = 0;
	ic.img = mlx_new_image(mlx, \
		settings()->player_size, settings()->player_size);
	ic.data = mlx_get_data_addr(ic.img, &ic.bpp, &ic.size_line, &ic.endian);
	while (ic.y < settings()->player_size)
	{
		ic.x = 0;
		create_player_rows(&ic, settings()->player_size);
		ic.y++;
	}
	return (ic.img);
}

void	create_rows(t_image_creator *ic, char **map)
{
	while (ic->x < (int)ft_strlen(map[ic->y / settings()->map_size]) * \
		settings()->map_size)
	{
		ic->pix_index = (ic->x * ic->bpp / 8) + (ic->y * ic->size_line);
		if (map[ic->y / settings()->map_size] \
			[ic->x / settings()->map_size] == '1')
			*(unsigned int *)(ic->data + ic->pix_index) = GREY;
		else if (map[ic->y / settings()->map_size] \
			[ic->x / settings()->map_size] == '0' || \
			map[ic->y / settings()->map_size] \
			[ic->x / settings()->map_size] == 'C')
			*(unsigned int *)(ic->data + ic->pix_index) = BLACK;
		ic->x++;
	}
}

int	find_biggest_column(char **map)
{
	int		i;
	size_t	biggest_column;

	i = 0;
	biggest_column = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > biggest_column)
			biggest_column = ft_strlen(map[i]);
		i++;
	}
	return (biggest_column);
}

t_image_creator	create_image(void *mlx, t_lay lay, char **map)
{
	t_image_creator	ic;
	int				biggest_column;

	biggest_column = find_biggest_column(map);
	ic.img = mlx_new_image(mlx, biggest_column * settings()->map_size, \
		lay.n_row * settings()->map_size);
	ic.data = mlx_get_data_addr(ic.img, &ic.bpp, &ic.size_line, &ic.endian);
	ic.width = biggest_column * settings()->map_size;
	ic.height = lay.n_row * settings()->map_size;
	return (ic);
}
