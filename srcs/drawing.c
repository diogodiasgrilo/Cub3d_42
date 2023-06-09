/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:33:42 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/09 18:44:21 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void	draw_line(t_game *g, float pdx, float pdy, float ray_angle, int ray)
{
	t_line_drawing	rs;

	rs.x1 = (g->px * MAP_SIZE) + 2;
	rs.y1 = (g->py * MAP_SIZE) + 2;
	rs.x2 = ((g->px + pdx) * MAP_SIZE) + 2;
	rs.y2 = ((g->py + pdy) * MAP_SIZE) + 2;
	rs.dx = abs((rs.x2 - rs.x1));
	rs.dy = -abs((rs.y2 - rs.y1));
	rs.err = rs.dx + rs.dy;
	if (rs.x1 < rs.x2)
		rs.sx = 1;
	else
		rs.sx = -1;
	if (rs.y1 < rs.y2)
		rs.sy = 1;
	else
		rs.sy = -1;
	put_on_screen(g, &rs, ray_angle, ray);
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
	float	ray_angle;
	float	pdx;
	float	pdy;

	i = -1;
	ray_angle = g->pa - HALF_FOV + 0.0001;
	mlx_clear_image(&g->scene, 0xFF000000, WIDTH, HEIGHT);
	mlx_clear_image(&g->map_buffer, 0xFF000000, g->lay->n_col * MAP_SIZE, g->lay->n_row * MAP_SIZE);
	draw_map(&g->map_buffer, g->lay, g->map);
	while (++i < NUM_RAYS)
	{
		pdx = (double)cos(ray_angle) * WALL_HEIGHT;
		pdy = (double)sin(ray_angle) * WALL_HEIGHT;
		draw_line(g, pdx, pdy, ray_angle, i);
		ray_angle += DELTA_ANGLE;
	}
	mlx_put_image_to_window(g->id, g->w_id, g->scene.img, 0, 0);
	mlx_put_image_to_window(g->id, g->w_id, g->map_buffer.img, 0, 0);
	mlx_put_image_to_window(g->id, g->w_id, g->player, \
		g->px * MAP_SIZE, g->py * MAP_SIZE);
}
