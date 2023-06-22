/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:18:16 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/22 11:10:20 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	on_mouse_move(float dir)
{
	t_game	*game;

	game = get_game();
	if (!game)
		return ;
	game->pa += dir * PLAYER_CAMERA_SPEED;
	if (game->pa < 0)
		game->pa = 2 * PI;
	else if (game->pa > 2 * PI)
		game->pa -= game->pa;
	game->pdx = cos(game->pa) + 0.0001;
	game->pdy = sin(game->pa) + 0.0001;
}

void	handle_angles(t_game *g, int key)
{
	if (key == 65363)
	{
		g->pa += PI / 12;
		if (g->pa > 2 * PI)
			g->pa = fmod(g->pa, 2 * PI);
		g->pdx = cos(g->pa);
		g->pdy = sin(g->pa);
		g->sky_offset_x += 180;
	}
	else if (key == 65361)
	{
		g->pa -= PI / 12;
		if (g->pa < 0)
			g->pa = 2 * PI + g->pa;
		g->pdx = cos(g->pa);
		g->pdy = sin(g->pa);
		g->sky_offset_x -= 180;
	}
}

void	change_directions(float *newx, float *newy, float oldx, float oldy)
{
	*newx = oldx;
	*newy = oldy;
}

bool	check_hitbox_point(t_game *g, float angle)
{
	int		pos[2];

	pos[0] = g->px + cos(angle) * 0.15;
	pos[1] = g->py + sin(angle) * 0.15;
	return (\
		pos[0] >= find_biggest_column(g->map) || \
		pos[1] >= find_biggest_column(g->map) || \
		pos[0] < 0 || pos[1] < 0 || \
		g->map[(int)floor(pos[1])][(int)floor(pos[0])] == '1' \
	);
}

int	check_hitbox(t_game *g, t_handle_directions *direc)
{
	float	angle;

	angle = atan2(direc->ndy, direc->ndx);
	if (check_hitbox_point(g, angle))
		return (true);
	angle += PI / 4;
	if (check_hitbox_point(g, angle))
		return (true);
	angle -= PI / 2;
	if (check_hitbox_point(g, angle))
		return (true);
	return (false);
}
