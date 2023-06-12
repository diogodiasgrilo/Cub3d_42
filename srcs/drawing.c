/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:33:42 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/12 09:19:15 by martiper         ###   ########.fr       */
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

static void	put_pixel(t_image_creator *image, int x, int y, int color)
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

void	draw_point(t_gfx_point point)
{
	put_pixel(point.buffer, point.x, point.y, point.color);
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

void	draw_map(t_image_creator *ic, t_lay *lay, char **map)
{
	ic->y = 0;
	while (ic->y < lay->n_row * MAP_SIZE)
	{
		ic->x = 0;
		create_rows(ic, *lay, map);
		ic->y++;
	}
}

void	draw_rays(t_game *g)
{
	int		i;
	int		j;

	i = -1;
	g->ray_angle = g->pa - HALF_FOV + 0.0001;
	mlx_clear_image(&g->scene, 0xFF000000, WIDTH, HEIGHT);
	mlx_clear_image(&g->map_buffer, 0xFF000000, g->lay->n_col * MAP_SIZE, g->lay->n_row * MAP_SIZE);
	draw_map(&g->map_buffer, g->lay, g->map);
	g->x_map = (int)g->px;
	g->y_map = (int)g->py;

	while (++i < NUM_RAYS)
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
		while (++j < WIDTH * 2)
		{
			if (g->y_hor >= g->lay->n_row || g->x_hor >= g->lay->n_col || g->y_hor < 0 || g->x_hor < 0 || g->map[(int)g->y_hor][(int)g->x_hor] == '1')
				break ;
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
		while (++j < WIDTH * 2)
		{
			if (g->y_vert >= g->lay->n_row || g->x_vert >= g->lay->n_col || g->y_vert < 0 || g->x_vert < 0 || g->map[(int)g->y_vert][(int)g->x_vert] == '1')
				break ;
			g->x_vert += g->dx;
			g->y_vert += g->dy;
			g->depth_vert += g->delta_depth;
		}

		// double tex_offset;
		if (g->depth_vert < g->depth_hor)
		{
			g->depth = g->depth_vert;
			g->y_vert = fmod(g->y_vert, 1);
			// if (g->cos_a > 0)
			// 	tex_offset = g->y_vert;
			// else
			// 	tex_offset = 1 - g->y_vert;
		}
		else
		{
			g->depth = g->depth_hor;
			g->x_hor = fmod(g->x_hor, 1);
			// if (g->sin_a > 0)
			// 	tex_offset = 1 - g->x_hor;
			// else
			// 	tex_offset = g->x_hor;
		}


		#if DRAW_MINIMAP
			draw_line((t_gfx_line){
				.buffer = &g->map_buffer,
				.start_x = g->px * MAP_SIZE,
				.start_y = g->py * MAP_SIZE,
				.direction_x = g->cos_a,
				.direction_y = g->sin_a,
				.length = g->depth * MAP_SIZE,
				.color = 0xFFFFFFFF
			});
		#endif
		#if DRAW_WORLD
			g->depth *= cos(g->ray_angle - g->pa);
			t_put_on_screen	projection;

			projection.color = 0xFFFFFFFF;
			projection.proj_height = SCREEN_DIST / (g->depth + 0.0001);
			if (projection.proj_height > HEIGHT)
				projection.proj_height = HEIGHT;
			determine_color(&projection);
			draw_rect((t_gfx_rect){
				.buffer = &g->scene,
				.start_x = i * SCALE,
				.start_y = HALF_HEIGHT - (int)(projection.proj_height / 2),
				.width = SCALE,
				.height = (int)projection.proj_height,
				.color = projection.color
			});
			/* draw_line((t_gfx_line){
				.buffer = &g->scene,
				.start_x = i * SCALE,
				.start_y = (HALF_HEIGHT - (int)(projection.proj_height / 2)),
				.length = projection.proj_height,
				.direction_x = 0,
				.direction_y = 1,
				.color = projection.color
			}); */
		#endif
		g->ray_angle += DELTA_ANGLE;
	}
	draw_line((t_gfx_line){
		.buffer = &g->map_buffer,
		.start_x = g->px * MAP_SIZE,
		.start_y = g->py * MAP_SIZE,
		.direction_x = cos(g->pa),
		.direction_y = sin(g->pa),
		.length = 10,
		.color = 0xFFFF0000
	});
	//anti_aliasing_top_left(g);
	//anti_aliasing_bottom_left(g);
	//anti_aliasing_top_right(g);
	//anti_aliasing_bottom_right(g);
	#if DRAW_WORLD
		mlx_put_image_to_window(g->id, g->w_id, g->scene.img, 0, 0);
	#endif
	#if DRAW_MINIMAP
		mlx_put_image_to_window(g->id, g->w_id, g->map_buffer.img, 0, 0);
	#endif
	/* mlx_put_image_to_window(g->id, g->w_id, g->player, \
		g->px * MAP_SIZE - HALF_PLAYER_SIZE, g->py * MAP_SIZE - HALF_PLAYER_SIZE); */
}
