/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:30:49 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 16:51:35 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void	finalize_directions(t_handle_directions *direc, t_game *g)
{
	direc->npx = g->px + direc->ndx * 0.1;
	direc->npy = g->py + direc->ndy * 0.1;
	if (check_hitbox(g, direc))
		return ;
	g->px = direc->npx;
	g->py = direc->npy;
}

void	handle_directions(t_game *g, char dir)
{
	t_handle_directions	direc;

	direc.fx = g->pdx;
	direc.fy = g->pdy;
	direc.rx = -direc.fy;
	direc.ry = direc.fx;
	if (dir == 'f')
		change_directions(&direc.ndx, &direc.ndy, direc.fx, direc.fy);
	else if (dir == 'b')
		change_directions(&direc.ndx, &direc.ndy, -direc.fx, -direc.fy);
	else if (dir == 'l')
	{
		change_directions(&direc.ndx, &direc.ndy, -direc.rx, -direc.ry);
		g->sky_offset_x -= 1;
	}
	else if (dir == 'r')
	{
		change_directions(&direc.ndx, &direc.ndy, direc.rx, direc.ry);
		g->sky_offset_x += 1;
	}
	else
		return ;
	finalize_directions(&direc, g);
}

int	ft_input(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	g->pdx = cos(g->pa);
	g->pdy = sin(g->pa);
	if (key == 65363 || key == 65361)
		handle_angles(g, key);
	else if (key == 119)
		handle_directions(g, 'f');
	else if (key == 115)
		handle_directions(g, 'b');
	else if (key == 97)
		handle_directions(g, 'l');
	else if (key == 100)
		handle_directions(g, 'r');
	else if (key == 65307)
		exit(0);
	return (0);
}

int	on_new_frame(void)
{
	t_game	*game;
	int		mx;
	int		my;

	game = get_game();
	if (!game)
		return (0);
	mlx_mouse_hide(game->id, game->w_id);
	mlx_mouse_get_pos(game->id, game->w_id, &mx, &my);
	if (mx < MOUSE_SAFE_AREA_LEFT || mx > MOUSE_SAFE_AREA_RIGHT)
		mlx_mouse_move(game->id, game->w_id, HALF_WIDTH, HALF_HEIGHT);
	else if (fabs(mx - HALF_WIDTH) > MOUSE_SENSITIVITY)
		on_mouse_move((mx - HALF_WIDTH) / (float)(HALF_WIDTH));
	draw_rays(game);
	return (0);
}
