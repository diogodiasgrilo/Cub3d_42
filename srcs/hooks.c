/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:30:49 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/11 10:58:23 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include <vectors.h>

int	free_map_exit(void *game)
{
	int		i;
	t_game	*g;

	i = -1;
	g = (t_game *)game;
	mlx_loop_end(g->id);
	while (g->map[++i])
		free(g->map[i]);
	free(g->map);
	mlx_destroy_image(g->id, g->player);
	mlx_destroy_window(g->id, g->w_id);
	mlx_destroy_display(g->id);
	free(g->id);
	exit(0);
}

void	handle_angles(t_game *g, int key)
{
	if (key == 65363)
	{
		g->pa += 0.15;
		if (g->pa > 2 * PI)
			g->pa -= g->pa;
		g->pdx = cos(g->pa) * MINIMAP_RATIO;
		g->pdy = sin(g->pa) * MINIMAP_RATIO;
	}
	else if (key == 65361)
	{
		g->pa -= 0.15;
		if (g->pa < 0)
			g->pa = 2 * PI;
		g->pdx = cos(g->pa) * MINIMAP_RATIO;
		g->pdy = sin(g->pa) * MINIMAP_RATIO;
	}
}

void	handle_directions_1(t_game *g, int one_dif)
{
	if (g->map[g->py][g->px - one_dif] != '1' && \
		g->pa < 3.983188 && g->pa > 1.883189)
		g->px -= one_dif;
	else if (g->map[g->py][g->px + one_dif] != '1' \
		&& (g->pa < 0.800000 || g->pa > 5.983186))
		g->px += one_dif;
	else if (g->map[g->py - one_dif][g->px] != '1' \
		&& g->pa < 5.983186 && g->pa > 3.983188)
		g->py -= one_dif;
	else if (g->map[(g->py + one_dif)][g->px] != '1' \
		&& g->pa < 1.883189 && g->pa > 0.783189)
		g->py += one_dif;
}

void	handle_directions_2(t_game *g, int one_dif)
{
	if (g->map[g->py - one_dif][g->px] != '1' && \
		(g->pa > 5.983186 || g->pa < 0.800000))
		g->py -= one_dif;
	else if (g->map[g->py + one_dif][g->px] != '1' \
		&& (g->pa < 3.983188 && g->pa > 1.883189))
		g->py += one_dif;
	else if (g->map[g->py][g->px - one_dif] != '1' \
		&& g->pa < 5.983186 && g->pa > 3.983188)
		g->px -= one_dif;
	else if (g->map[(g->py)][g->px + one_dif] != '1' \
		&& g->pa < 1.883189 && g->pa > 0.783189)
		g->px += one_dif;
}

int	ft_input(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key == 65363 || key == 65361)
		handle_angles(g, key);
	else if (key == 119)
		handle_directions_1(g, 1);
	else if (key == 115)
		handle_directions_1(g, -1);
	else if (key == 97)
		handle_directions_2(g, 1);
	else if (key == 100)
		handle_directions_2(g, -1);
	else if (key == 65307)
		exit(0);
	draw_rays(g);
	return (0);
}

static void	on_mouse_move(int dir)
{
	t_game	*game;

	game = get_game();
	if (!game)
		return ;
	if (dir * PLAYER_CAMERA_SPEED > 0.1 || dir * PLAYER_CAMERA_SPEED < -0.1)
		return ;
	game->pa += dir * PLAYER_CAMERA_SPEED;
	if (game->pa < 0)
		game->pa = 2 * PI + game->pa;
	else if (game->pa > 2 * PI)
		game->pa = fmod(game->pa, 2 * PI);
	game->pdx = cos(game->pa) * MINIMAP_RATIO;
	game->pdy = sin(game->pa) * MINIMAP_RATIO;
	draw_rays(game);
}

int	on_new_frame(void)
{
	t_game	*game;
	t_vec2	mouse_pos;

	game = get_game();
	if (!game)
		return (0);
	mlx_mouse_get_pos(game->id, game->w_id, &mouse_pos.x, &mouse_pos.y);
	if (mouse_pos.x < 0 || mouse_pos.x > WIDTH || mouse_pos.y < 0 || mouse_pos.y > HEIGHT)
		return (0);
	on_mouse_move(mouse_pos.x - WIDTH / 2);
	return (0);
}
