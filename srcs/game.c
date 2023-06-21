/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:09:21 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/20 20:54:27 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void	find_angle_direction(t_game *g)
{
	if (g->direction == 'E')
		g->pa = PI * 2;
	else if (g->direction == 'W')
		g->pa = PI;
	else if (g->direction == 'N')
		g->pa = PI * 3 / 2;
	else if (g->direction == 'S')
		g->pa = PI / 2;
}

void	start_game(char **map, t_lay lay, t_map_errors *parsed)
{
	t_game		g;
	t_textures textures;

	g.lay_bak = lay;
	g.parsed = parsed;
	g.textures = &textures;
	g.sky_offset_x = 0;
	g.id = mlx_init();
	load_textures(&g, parsed);
	g.w_id = mlx_new_window(g.id, WIDTH, HEIGHT,
			"Raycaster");
	g.scene.img = mlx_new_image(g.id, WIDTH * 2, HEIGHT * 2);
	g.scene.data = mlx_get_data_addr(g.scene.img, &g.scene.bpp,
			&g.scene.size_line, &g.scene.endian);
	g.scene.width = WIDTH * 2;
	g.scene.height = HEIGHT * 2;
	g.map_buffer = create_image(g.id, lay, map);
	g.player = create_player(g.id);
	ft_newgame(&g, map, &lay);
	find_player(&g, map);
	mlx_put_image_to_window(g.id, g.w_id, g.player, \
		g.px * MAP_SIZE, g.py * MAP_SIZE);
	g.pdx = (cos(g.pa) * MAP_SIZE);
	g.pdy = (sin(g.pa) * MAP_SIZE);
	find_angle_direction(&g);
	draw_rays(&g);
	mlx_hook(g.w_id, 17, 0, free_map_exit, &g);
	mlx_hook(g.w_id, 2, 1L<<0, *ft_input, &g);
	mlx_hook(g.w_id, 3, 1L<<1, *ft_release, &g);
	mlx_loop(g.id);
}

void	ft_newgame(t_game *g, char **m, t_lay *lay)
{
	g->width = 0;
	g->height = 0;
	g->lay = lay;
	g->map = m;
}

void	find_player(t_game *g, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				g->direction = map[i][j];
				g->px = j + 0.5;
				g->py = i + 0.5;
				return ;
			}
		}
	}
}
