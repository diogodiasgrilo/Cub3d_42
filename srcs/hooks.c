/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:30:49 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/12 17:23:10 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

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
		g->keys[5] = 1;
		g->pa += PI / 12;
		if (g->pa > 2 * PI)
			g->pa = fmod(g->pa, 2 * PI);
		g->pdx = cos(g->pa);
		g->pdy = sin(g->pa);
	}
	else if (key == 65361)
	{
		g->keys[4] = 1;
		g->pa -= PI / 12;
		if (g->pa < 0)
			g->pa = 2 * PI + g->pa;
		g->pdx = cos(g->pa);
		g->pdy = sin(g->pa);
	}
}

void	handle_directions(t_game *g, char dir)
{
	float	npx;
	float	npy;
	float	ndx;
	float	ndy;
	float	fx;
	float	fy;
	float	rx;
	float	ry;

	fx = g->pdx;
	fy = g->pdy;
	rx = -fy;
	ry = fx;
	if (dir == 'f')
	{
		ndx = fx;
		ndy = fy;
	}
	else if (dir == 'b')
	{
		ndx = -fx;
		ndy = -fy;
	}
	else if (dir == 'l')
	{
		ndx = -rx;
		ndy = -ry;
	}
	else if (dir == 'r')
	{
		ndx = rx;
		ndy = ry;
	}
	else
		return ;
	npx = g->px + ndx * 0.1;
	npy = g->py + ndy * 0.1;
	if (npx >= g->lay->n_col || npy >= g->lay->n_col || npx < 0 || npy < 0 || g->map[(int)npy][(int)npx] == '1')
		return ;
	g->px = npx;
	g->py = npy;
}

int	ft_input(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key == 65363 || key == 65361)
		handle_angles(g, key);
	else if (key == 119)
	{
		g->keys[0] = 1;
		handle_directions(g, 'f');
	}
	else if (key == 115)
	{
		g->keys[1] = 1;
		handle_directions(g, 'b');
	}
	else if (key == 97)
	{
		g->keys[2] = 1;
		handle_directions(g, 'l');
	}
	else if (key == 100)
	{
		g->keys[3] = 1;
		handle_directions(g, 'r');
	}
	else if (key == 65307)
		exit(0);
	draw_rays(g);
	return (0);
}

int	ft_release(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key == 65363)
		g->keys[5] = 0;
	else if (key == 65361)
		g->keys[4] = 0;
	else if (key == 119)
		g->keys[0] = 0;
	else if (key == 115)
		g->keys[1] = 0;
	else if (key == 97)
		g->keys[2] = 0;
	else if (key == 100)
		g->keys[3] = 0;
	draw_rays(g);
	return (0);
}
