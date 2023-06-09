/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:30:49 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/09 20:25:15 by diogpere         ###   ########.fr       */
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
	if (key == 100)
	{
		g->pa += 0.1;
		if (g->pa > 2 * PI)
			g->pa -= g->pa;
		g->pdx = cos(g->pa) * MINIMAP_RATIO;
		g->pdy = sin(g->pa) * MINIMAP_RATIO;
	}
	else if (key == 97)
	{
		g->pa -= 0.1;
		if (g->pa < 0)
			g->pa = 2 * PI;
		g->pdx = cos(g->pa) * MINIMAP_RATIO;
		g->pdy = sin(g->pa) * MINIMAP_RATIO;
	}
}

void	handle_directions(t_game *g, int one_dif)
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

int	ft_input(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key == 100 || key == 97)
		handle_angles(g, key);
	else if (key == 119)
		handle_directions(g, 1);
	else if (key == 115)
		handle_directions(g, -1);
	else if (key == 65307)
		exit(0);
	draw_rays(g);
	return (0);
}
