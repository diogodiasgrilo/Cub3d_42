/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:55:26 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 18:10:51 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void	draw_whole_image_again(t_game *g)
{
	put_portal_gun(g);
	mlx_put_image_to_window(g->id, g->w_id, g->scene.img, 0, 0);
	mlx_put_image_to_window(g->id, g->w_id, g->map_buffer.img, 0, 0);
	mlx_put_image_to_window(g->id, g->w_id, g->player, \
		g->px * MAP_SIZE - settings()->half_player_size, g->py * \
		MAP_SIZE - settings()->half_player_size);
}

void	draw_map(t_image_creator *ic, t_lay *lay, char **map)
{
	ic->y = 0;
	while (ic->y < lay->n_row * MAP_SIZE)
	{
		ic->x = 0;
		create_rows(ic, map);
		ic->y++;
	}
}

void	draw_rect(t_gfx_rect rect)
{
	int	x;
	int	y;

	y = rect.start_y;
	while (y < rect.start_y + rect.height)
	{
		x = rect.start_x;
		while (x < rect.start_x + rect.width)
		{
			put_pixel(rect.buffer, x, y, rect.color);
			x++;
		}
		y++;
	}
}

void	assign_pixel_color_and_put(t_put_on_screen *prog, t_game *g, \
	t_texture *texture, int i)
{
	prog->texture_x = (prog->y - (settings()->half_height - \
	(int)(prog->proj_height / 2))) * (texture->width - settings()->scale) \
	/ (int)prog->proj_height;
	prog->color = (*(unsigned int *)(texture->data + ((prog->texture_x * \
	texture->size_line) + (prog->texture_y * (texture->bpp / 8)))));
	put_pixel(&g->scene, i * settings()->scale, prog->y, prog->color);
	prog->y += 1;
}

void	create_image_on_screen(t_texture	*texture, t_game *g, int i)
{
	t_put_on_screen	proj;

	proj.color = 0xFFFFFFFF;
	proj.proj_height = settings()->screen_dist / (g->depth + 0.0001);
	proj.texture_y = (int)(g->textures->offset * \
		(texture->height - settings()->scale));
	proj.y = settings()->half_height - (int)(proj.proj_height / 2);
	proj.end_y = settings()->half_height + (int)(proj.proj_height / 2);
	if (proj.y < 0)
		proj.y = 0;
	else if (proj.y >= HEIGHT)
		proj.y = HEIGHT - 1;
	if (proj.end_y < 0)
		proj.end_y = 0;
	else if (proj.end_y >= HEIGHT)
		proj.end_y = HEIGHT - 1;
	while (proj.y < proj.end_y)
		assign_pixel_color_and_put(&proj, g, texture, i);
	create_floor_sky(g, proj, i * settings()->scale);
	g->ray_angle += settings()->delta_angle;
}
