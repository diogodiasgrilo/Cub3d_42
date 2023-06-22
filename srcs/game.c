/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:09:21 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/22 13:39:06 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	get_game_ready(t_game *g, char **map, t_lay lay, t_map_errors *parsed)
{
	g->lay_bak = lay;
	g->parsed = parsed;
	g->sky_offset_x = 0;
	g->id = mlx_init();
	load_textures(g, parsed);
	g->w_id = mlx_new_window(g->id, settings()->width, settings()->height,
			"Cub3D");
	g->scene.img = mlx_new_image(g->id, \
		settings()->width * 2, settings()->height * 2);
	g->scene.data = mlx_get_data_addr(g->scene.img, &g->scene.bpp, \
			&g->scene.size_line, &g->scene.endian);
	g->scene.width = settings()->width * 2;
	g->scene.height = settings()->height * 2;
	g->map_buffer = create_image(g->id, lay, map);
	mlx_mouse_move(g->id, g->w_id, settings()->width / 2, settings()->height / 2);
}

void	start_game(char **map, t_lay lay, t_map_errors *parsed)
{
	t_game		*g;
	t_textures	textures;

	g = get_game();
	g->textures = &textures;
	get_game_ready(g, map, lay, parsed);
	ft_newgame(g, map, &lay);
	find_player(g, map);
	g->pdx = (cos(g->pa) * settings()->map_size);
	g->pdy = (sin(g->pa) * settings()->map_size);
	find_angle_direction(g);
	g->pdx = cos(g->pa);
	g->pdy = sin(g->pa);
	draw_rays(g);
	mlx_hook(g->w_id, 17, 0, free_map_exit, g);
	mlx_hook(g->w_id, 2, 1L << 0, *ft_input, g);
	mlx_loop_hook(g->id, on_new_frame, NULL);
	mlx_loop(g->id);
}
