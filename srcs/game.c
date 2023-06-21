/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:09:21 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 18:57:23 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void	get_game_ready(t_game *g, char **map, t_lay lay, t_map_errors *parsed)
{
	g->lay_bak = lay;
	g->parsed = parsed;
	g->sky_offset_x = 0;
	g->id = mlx_init();
	load_textures(g, parsed);
	g->w_id = mlx_new_window(g->id, settings()->width, settings()->height,
			"Raycaster");
	g->scene.img = mlx_new_image(g->id, \
		settings()->width * 2, settings()->height * 2);
	g->scene.data = mlx_get_data_addr(g->scene.img, &g->scene.bpp, \
			&g->scene.size_line, &g->scene.endian);
	g->scene.width = settings()->width * 2;
	g->scene.height = settings()->height * 2;
	g->map_buffer = create_image(g->id, lay, map);
	g->player = create_player(g->id);
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
	mlx_put_image_to_window(g->id, g->w_id, g->player, \
		g->px * settings()->map_size, g->py * settings()->map_size);
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
