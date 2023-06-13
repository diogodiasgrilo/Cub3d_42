/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:51:16 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/12 19:35:46 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void    determine_color (t_put_on_screen        *sc)
{
	t_determine_color dc;
	
    dc.max_distance = 0.0f;
    dc.min_distance = 200.0f;
    dc.height = 0.0f;
    sc->color = 0xFFFFFF;
    if (sc->proj_height > dc.min_distance) {
        dc.height = dc.min_distance;
    } else if (sc->proj_height < dc.max_distance) {
        dc.height = dc.max_distance;
    }
    else
        dc.height = sc->proj_height;
    dc.ratio = (dc.height - dc.min_distance) / (dc.max_distance - dc.min_distance);
    dc.white = 0xFFFFFF;
    dc.grey = 0x808080;
    dc.red = (int)(((dc.white >> 16) & 0xFF) * (1.0f - dc.ratio) + ((dc.grey >> 16) & 0xFF) * dc.ratio);
    dc.green = (int)(((dc.white >> 8) & 0xFF) * (1.0f - dc.ratio) + ((dc.grey >> 8) & 0xFF) * dc.ratio);
    dc.blue = (int)((dc.white & 0xFF) * (1.0f - dc.ratio) + (dc.grey & 0xFF) * dc.ratio);
    sc->color = (dc.red << 16) | (dc.green << 8) | dc.blue;
}

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
	ic.img = mlx_new_image(mlx, PLAYER_SIZE, PLAYER_SIZE);
	ic.data = mlx_get_data_addr(ic.img, &ic.bpp, &ic.size_line, &ic.endian);
	while (ic.y < PLAYER_SIZE)
	{
		ic.x = 0;
		create_player_rows(&ic, PLAYER_SIZE);
		ic.y++;
	}
	return (ic.img);
}

void	create_rows(t_image_creator *ic, t_lay lay, char **map)
{
	while (ic->x < lay.n_col * MAP_SIZE)
	{
		ic->pix_index = (ic->x * ic->bpp / 8) + (ic->y * ic->size_line);
		if (map[ic->y / MAP_SIZE][ic->x / MAP_SIZE] == '1')
			*(unsigned int *)(ic->data + ic->pix_index) = GREY;
		else if (map[ic->y / MAP_SIZE][ic->x / MAP_SIZE] == '0' || \
			map[ic->y / MAP_SIZE][ic->x / MAP_SIZE] == 'C')
			*(unsigned int *)(ic->data + ic->pix_index) = BLACK;
		ic->x++;
	}
}

t_image_creator	create_image(void *mlx, t_lay lay, char **map)
{
	t_image_creator	ic;

	ic.img = mlx_new_image(mlx, lay.n_col * MAP_SIZE, lay.n_row * MAP_SIZE);
	ic.data = mlx_get_data_addr(ic.img, &ic.bpp, &ic.size_line, &ic.endian);
	ic.width = lay.n_col * MAP_SIZE;
	ic.height = lay.n_row * MAP_SIZE;
	draw_map(&ic, &lay, map);
	return (ic);
}