/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:09:21 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/12 09:21:29 by martiper         ###   ########.fr       */
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

void	start_game(char **map, t_lay lay)
{
	t_game	g;

	g.lay_bak = lay;
	g.id = mlx_init();
	g.w_id = mlx_new_window(g.id, WIDTH, HEIGHT,
			"Raycaster");
	g.scene.img = mlx_new_image(g.id, WIDTH * 2, HEIGHT * 2);
	g.scene.data = mlx_get_data_addr(g.scene.img, &g.scene.bpp,
			&g.scene.size_line, &g.scene.endian);
	g.scene.width = WIDTH * 2;
	g.scene.height = HEIGHT * 2;
	g.demo_tex.img = mlx_xpm_file_to_image(g.id, "textures/demo.xpm",
			&g.demo_tex.width, &g.demo_tex.height);
	g.demo_tex.data = mlx_get_data_addr(g.demo_tex.img, &g.demo_tex.bpp,
			&g.demo_tex.size_line, &g.demo_tex.endian);
	g.map_buffer = create_image(g.id, lay, map);
	g.player = create_player(g.id);
	ft_newgame(&g, map, &lay);
	find_player(&g, map);
	find_angle_direction(&g);
	g.pdx = cos(g.pa);
	g.pdy = sin(g.pa);
	draw_rays(&g);
	mlx_hook(g.w_id, 17, 0, free_map_exit, &g);
	mlx_hook(g.w_id, 2, 1L << 0, *ft_input, &g);
	mlx_hook(g.w_id, 3, 1L << 1, *ft_release, &g);
	mlx_loop(g.id);
}

void	ft_newgame(t_game *g, char **m, t_lay *lay)
{
	g->width = lay->n_col * MINIMAP_RATIO;
	g->height = lay->n_row * MINIMAP_RATIO;
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
