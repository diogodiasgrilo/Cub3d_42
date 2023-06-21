/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:33:42 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 18:02:19 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

t_texture	*if_hor_is_bigger(t_game *g)
{
	g->textures->texture = g->textures->texture_vert;
	g->depth = g->depth_vert;
	g->y_vert = fmod(g->y_vert, 1);
	if (g->cos_a > 0)
	{
		g->textures->offset = g->y_vert;
		return (g->textures->west);
	}
	else
	{
		g->textures->offset = 1 - g->y_vert;
		return (g->textures->east);
	}
}

t_texture	*if_ver_is_bigger(t_game *g)
{
	g->textures->texture = g->textures->texture_hor;
	g->depth = g->depth_hor;
	g->x_hor = fmod(g->x_hor, 1);
	if (g->sin_a > 0)
	{
		g->textures->offset = 1 - g->x_hor;
		return (g->textures->north);
	}
	else
	{
		g->textures->offset = g->x_hor;
		return (g->textures->south);
	}
}

t_texture	*assign_correct_texture(t_game *g)
{
	if (g->depth_vert < g->depth_hor)
		return (if_hor_is_bigger(g));
	else
		return (if_ver_is_bigger(g));
}

void	get_texture_and_put_on_screen(t_game *g, int i)
{
	t_texture	*texture;

	texture = assign_correct_texture(g);
	draw_line((t_gfx_line){
		.buffer = &g->map_buffer,
		.start_x = g->px * MAP_SIZE,
		.start_y = g->py * MAP_SIZE,
		.direction_x = g->cos_a,
		.direction_y = g->sin_a,
		.length = g->depth * MAP_SIZE,
		.color = 0xFFFFFFFF
	});
	g->depth *= cos(g->ray_angle - g->pa);
	create_image_on_screen(texture, g, i);
}

void	draw_rays(t_game *g)
{
	int			i;

	i = -1;
	g->ray_angle = g->pa - settings()->half_fov + 0.0001;
	mlx_clear_image(&g->scene, 0xFF000000, WIDTH, HEIGHT);
	mlx_clear_image(&g->map_buffer, 0xFF000000, find_biggest_column(g->map) \
		* MAP_SIZE, g->lay->n_row * MAP_SIZE);
	draw_map(&g->map_buffer, g->lay, g->map);
	g->x_map = (int)g->px;
	g->y_map = (int)g->py;
	while (++i < settings()->num_rays)
	{
		do_for_each_ray(g);
		get_texture_and_put_on_screen(g, i);
	}
	draw_whole_image_again(g);
}
