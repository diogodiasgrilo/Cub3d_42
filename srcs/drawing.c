/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:33:42 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 17:19:00 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

static void	*get_pixel_address(t_image_creator *image, int x, int y)
{
	return ((void *)(\
		image->data + \
		((y * image->size_line) + \
		(x * (image->bpp / 8)) \
	)));
}

void	put_pixel(t_image_creator *image, int x, int y, int color)
{
	void	*pixel;

	if (\
		x < 0 || x >= image->width || \
		y < 0 || y >= image->height \
	)
		return ;
	pixel = get_pixel_address(image, x, y);
	*(unsigned int *)pixel = color;
}

void	draw_line(t_gfx_line line)
{
	t_line_drawing	rs;

	rs.x1 = line.start_x;
	rs.y1 = line.start_y;
	rs.x2 = line.start_x + line.direction_x * line.length;
	rs.y2 = line.start_y + line.direction_y * line.length;
	rs.dx = abs(rs.x2 - rs.x1);
	rs.dy = -abs(rs.y2 - rs.y1);
	rs.err = rs.dx + rs.dy;
	if (rs.x1 < rs.x2)
		rs.sx = 1;
	else
		rs.sx = -1;
	if (rs.y1 < rs.y2)
		rs.sy = 1;
	else
		rs.sy = -1;
	while (1)
	{
		put_pixel(line.buffer, rs.x1, rs.y1, line.color);
		if (rs.x1 == rs.x2 && rs.y1 == rs.y2)
			break ;
		rs.e2 = 2 * rs.err;
		if (rs.e2 >= rs.dy)
		{
			rs.err += rs.dy;
			rs.x1 += rs.sx;
		}
		if (rs.e2 <= rs.dx)
		{
			rs.err += rs.dx;
			rs.y1 += rs.sy;
		}
	}
}

void	draw_map(t_image_creator *ic, t_lay *lay, char **map)
{
	ic->y = 0;
	while (ic->y < lay->n_row * settings()->map_size)
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

void	draw_rays(t_game *g)
{
	int			i;
	int			j;

	i = -1;
	g->ray_angle = g->pa - settings()->half_fov + 0.0001;
	mlx_clear_image(&g->scene, 0xFF000000, settings()->width, settings()->height);
	mlx_clear_image(&g->map_buffer, 0xFF000000, find_biggest_column(g->map) * settings()->map_size, g->lay->n_row * settings()->map_size);
	draw_map(&g->map_buffer, g->lay, g->map);
	g->x_map = (int)g->px;
	g->y_map = (int)g->py;
	while (++i < settings()->num_rays)
	{
		g->x_hor = g->px;
		g->y_hor = g->py;
		g->x_vert = g->px;
		g->y_vert = g->py;
		g->sin_a = sin(g->ray_angle);
		g->cos_a = cos(g->ray_angle);
		// Horizontal Lines
		if (g->sin_a > 0)
		{
			g->y_hor = g->y_map + 1;
			g->dy = 1;
		}
		else
		{
			g->y_hor = g->y_map - 1e-6;
			g->dy = -1;
		}
		g->depth_hor = (g->y_hor - g->py) / g->sin_a;
		g->x_hor = g->px + g->depth_hor * g->cos_a;

		g->delta_depth = g->dy / g->sin_a;
		g->dx = g->delta_depth * g->cos_a;

		j = -1;
		while (++j < settings()->width * 5)
		{
			if (g->y_hor >= g->lay->n_row || g->x_hor >= \
				(int)ft_strlen(g->map[(int)g->y_hor]) || \
				g->y_hor < 0 || g->x_hor < 0 || \
				((int)g->x_hor < (int)ft_strlen(g->map[(int)g->y_hor]) \
				&& g->map[(int)g->y_hor][(int)g->x_hor] == '1'))
			{
				g->textures->texture_hor = g->textures->south;
				break ;
			}
			g->x_hor += g->dx;
			g->y_hor += g->dy;
			g->depth_hor += g->delta_depth;
		}
		// Vertical Lines
		if (g->cos_a > 0)
		{
			g->x_vert = g->x_map + 1;
			g->dx = 1;
		}
		else
		{
			g->x_vert = g->x_map - 1e-6;
			g->dx = -1;
		}
		g->depth_vert = (g->x_vert - g->px) / g->cos_a;
		g->y_vert = g->py + g->depth_vert * g->sin_a;

		g->delta_depth = g->dx / g->cos_a;
		g->dy = g->delta_depth * g->sin_a;

		j = -1;
		while (++j < settings()->width * 5)
		{
			if (g->y_vert >= g->lay->n_row || ((int)g->y_vert > 0 && \
				g->x_vert >= (int)ft_strlen(g->map[(int)g->y_vert])) \
				|| g->y_vert < 0 || g->x_vert < 0 || \
				((int)g->x_vert < (int)ft_strlen(g->map[(int)g->y_vert]) \
				&& g->map[(int)g->y_vert][(int)g->x_vert] == '1'))
			{
				g->textures->texture_vert = g->textures->south;
				break ;
			}
			g->x_vert += g->dx;
			g->y_vert += g->dy;
			g->depth_vert += g->delta_depth;
		}

		t_texture	*texture;

		if (g->depth_vert < g->depth_hor)
		{
			g->textures->texture = g->textures->texture_vert;
			g->depth = g->depth_vert;
			g->y_vert = fmod(g->y_vert, 1);
			if (g->cos_a > 0)
			{
				g->textures->offset = g->y_vert;
				texture = g->textures->west;
			}
			else
			{
				g->textures->offset = 1 - g->y_vert;
				texture = g->textures->east;
			}
		}
		else
		{
			g->textures->texture = g->textures->texture_hor;
			g->depth = g->depth_hor;
			g->x_hor = fmod(g->x_hor, 1);
			if (g->sin_a > 0)
			{
				g->textures->offset = 1 - g->x_hor;
				texture = g->textures->north;
			}
			else
			{
				g->textures->offset = g->x_hor;
				texture = g->textures->south;
			}
		}
		draw_line((t_gfx_line){
			.buffer = &g->map_buffer,
			.start_x = g->px * settings()->map_size,
			.start_y = g->py * settings()->map_size,
			.direction_x = g->cos_a,
			.direction_y = g->sin_a,
			.length = g->depth * settings()->map_size,
			.color = 0xFFFFFFFF
		});
		g->depth *= cos(g->ray_angle - g->pa);

		t_put_on_screen	proj;

		proj.color = 0xFFFFFFFF;
		proj.proj_height = settings()->screen_dist / (g->depth + 0.0001);
		// if (proj.proj_height > settings()->height)
			// proj.proj_height = settings()->height;
		proj.texture_y = (int)(g->textures->offset * (texture->height - settings()->scale));
		proj.y = settings()->half_height - (int)(proj.proj_height / 2);
		proj.end_y = settings()->half_height + (int)(proj.proj_height / 2);
		if (proj.y < 0)
			proj.y = 0;
		else if (proj.y >= settings()->height)
			proj.y = settings()->height - 1;
		if (proj.end_y < 0)
			proj.end_y = 0;
		else if (proj.end_y >= settings()->height)
			proj.end_y = settings()->height - 1;
		while (proj.y < proj.end_y)
		{
			proj.texture_x = (proj.y - (settings()->half_height - (int)(proj.proj_height / 2))) * (texture->width - settings()->scale) / (int)proj.proj_height;
			proj.color = (*(unsigned int*)(texture->data + ((proj.texture_x * texture->size_line) + (proj.texture_y * (texture->bpp / 8)))));
			put_pixel(&g->scene, i * settings()->scale, proj.y, proj.color);
			proj.y++;
		}
		create_floor_sky(g, proj, i * settings()->scale);
		g->ray_angle += settings()->delta_angle;
	}
	put_portal_gun(g);
	mlx_put_image_to_window(g->id, g->w_id, g->scene.img, 0, 0);
	mlx_put_image_to_window(g->id, g->w_id, g->map_buffer.img, 0, 0);
	mlx_put_image_to_window(g->id, g->w_id, g->player, \
		g->px * settings()->map_size - settings()->half_player_size, g->py * settings()->map_size - settings()->half_player_size);
}
