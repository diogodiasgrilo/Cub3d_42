/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:52:15 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/22 11:10:20 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	put_sky(t_game *g)
{
	int	y;
	int	x;
	int	sky_x;
	int	sky_y;
	int	color;

	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
		{
			sky_x = ((int)(x + g->sky_offset_x) % g->textures->sky->width \
				+ g->textures->sky->width) % g->textures->sky->width;
			sky_y = y * g->textures->sky->height / (HEIGHT / 1.5);
			color = *(int *)(g->textures->sky->data + sky_y * \
				g->textures->sky->size_line + sky_x * \
				g->textures->sky->bpp / 8);
			my_mlx_pixel_put(&g->scene, x, y, color);
		}
	}
}

void	put_portal_gun(t_game *g)
{
	t_portal_gun	pg;

	pg.gun_data = g->textures->portal_gun->data;
	pg.gun_width = g->textures->portal_gun->width;
	pg.gun_height = g->textures->portal_gun->height;
	pg.x_start = WIDTH - pg.gun_width / 1.7;
	pg.y_start = HEIGHT - pg.gun_height / 1.1;
	pg.y = -1;
	while (++pg.y < pg.gun_height)
	{
		pg.x = -1;
		while (++pg.x < pg.gun_width)
		{
			pg.color = *(int *)(pg.gun_data + pg.y * \
				g->textures->portal_gun->size_line \
				+ pg.x * g->textures->portal_gun->bpp / 8);
			if (!(pg.color >> 24 & 0xFF))
				my_mlx_pixel_put(&g->scene, pg.x_start + pg.x, \
					pg.y_start + pg.y, pg.color);
		}
	}
}

void	*create_floor_sky(t_game *g, t_put_on_screen proj, int i)
{
	t_image_creator	ic;

	ic.y = 0;
	while (ic.y <= (proj.y - proj.proj_height) + 3)
	{
		ic.x = 0;
		put_pixel(&g->scene, i, ic.y, g->parsed->ceiling_color);
		ic.y++;
	}
	ic.y = HEIGHT;
	while (ic.y >= proj.y - 3)
	{
		ic.x = 0;
		put_pixel(&g->scene, i, ic.y, g->parsed->floor_color);
		ic.y--;
	}
	return (NULL);
}
