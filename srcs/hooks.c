/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:30:49 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/11 12:03:58 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include <vectors.h>

typedef enum e_keycodes
{
	KEYCODE_ESCAPE = 65307,
	KEYCODE_W = 119,
	KEYCODE_A = 97,
	KEYCODE_S = 115,
	KEYCODE_D = 100,
	KEYCODE_ARROW_UP = 65362,
	KEYCODE_ARROW_LEFT = 65361,
	KEYCODE_ARROW_DOWN = 65364,
	KEYCODE_ARROW_RIGHT = 65363,
	KEYCODE_E = 101,
}						t_keycodes;

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

/*
	dir is a vector based on the player's direction
 */
void	handle_directions(t_game *g, t_vec2f dir)
{
	t_vec2f	new_pos;
	t_vec2f	player_dir;

	player_dir = vec2f(cos(g->pa), sin(g->pa));
	dir = vec2f_mul_scal(dir, PLAYER_SPEED);
	dir = vec2f_mul(dir, player_dir);
	new_pos = vec2f_add(vec2f(g->px, g->py), dir);
	if (g->map[(int)new_pos.y][(int)new_pos.x] != '1')
	{
		g->px = (int)new_pos.x;
		g->py = (int)new_pos.y;
	}
}

int	ft_input(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key == KEYCODE_ARROW_RIGHT || key == KEYCODE_ARROW_LEFT)
		handle_angles(g, key);
	else if (key == KEYCODE_W)
		handle_directions(g, vec2f(1.0f, 1.0f));
	else if (key == KEYCODE_S)
		handle_directions(g, vec2f(1.0f, 0.0f));
	else if (key == KEYCODE_A)
		handle_directions(g, vec2f(-1.0f, 0.0f));
	else if (key == KEYCODE_D)
		handle_directions(g, vec2f(-1.0f, -1.0f));
	else if (key == KEYCODE_ESCAPE)
		exit(0);
	draw_rays(g);
	return (0);
}

static void	on_mouse_move(float dir)
{
	t_game	*game;

	game = get_game();
	if (!game)
		return ;
	game->pa += dir * PLAYER_CAMERA_SPEED;
	if (game->pa < 0)
		game->pa = 2 * PI + game->pa;
	else if (game->pa > 2 * PI)
		game->pa = fmod(game->pa, 2 * PI);
	game->pdx = cos(game->pa) * MINIMAP_RATIO;
	game->pdy = sin(game->pa) * MINIMAP_RATIO;
	ft_printf("pa: %f\n", (2 * PI - game->pa) * 180 / PI);
	draw_rays(game);
}

int	on_new_frame(void)
{
	t_game	*game;
	t_vec2	mouse_pos;
	// static t_vec2	last_mouse_pos;

	game = get_game();
	if (!game)
		return (0);
	mlx_mouse_get_pos(game->id, game->w_id, &mouse_pos.x, &mouse_pos.y);
	if (mouse_pos.x < 0 || mouse_pos.x > WIDTH || mouse_pos.y < 0 || mouse_pos.y > HEIGHT)
	{
		mlx_mouse_move(game->id, game->w_id, HALF_WIDTH, HALF_HEIGHT);
		return (0);
	}
	if (fabs(mouse_pos.x - HALF_WIDTH) < MOUSE_SENSITIVITY)
		return (0);
	on_mouse_move((mouse_pos.x - HALF_WIDTH) / (float)(HALF_WIDTH));
	// last_mouse_pos = mouse_pos;
	return (0);
}
