/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:27:33 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/22 11:10:20 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	find_wall_for_hor_line(t_game *g)
{
	if (g->y_hor >= g->lay->n_row || g->x_hor >= \
		(int)ft_strlen(g->map[(int)g->y_hor]) || \
		g->y_hor < 0 || g->x_hor < 0 || \
		((int)g->x_hor < (int)ft_strlen(g->map[(int)g->y_hor]) \
		&& g->map[(int)g->y_hor][(int)g->x_hor] == '1'))
	{
		g->textures->texture_hor = g->textures->south;
		return (EXIT_FAILURE);
	}
	g->x_hor += g->dx;
	g->y_hor += g->dy;
	g->depth_hor += g->delta_depth;
	return (EXIT_SUCCESS);
}

void	deal_with_hor_intercept(t_game *g)
{
	int			j;

	if (g->sin_a > 0)
	{
		g->y_hor = g->y_map + 1;
		g->dy = 1;
	}
	else
	{
		g->y_hor = g->y_map - 1e-6;
		g->dy = -1;
	}
	g->depth_hor = (g->y_hor - g->py) / g->sin_a;
	g->x_hor = g->px + g->depth_hor * g->cos_a;
	g->delta_depth = g->dy / g->sin_a;
	g->dx = g->delta_depth * g->cos_a;
	j = -1;
	while (++j < WIDTH * 5)
		if (find_wall_for_hor_line(g))
			break ;
}

int	find_wall_for_vert_line(t_game *g)
{
	if (g->y_vert >= g->lay->n_row || ((int)g->y_vert > 0 && \
		g->x_vert >= (int)ft_strlen(g->map[(int)g->y_vert])) \
		|| g->y_vert < 0 || g->x_vert < 0 || \
		((int)g->x_vert < (int)ft_strlen(g->map[(int)g->y_vert]) \
		&& g->map[(int)g->y_vert][(int)g->x_vert] == '1'))
	{
		g->textures->texture_vert = g->textures->south;
		return (EXIT_FAILURE);
	}
	g->x_vert += g->dx;
	g->y_vert += g->dy;
	g->depth_vert += g->delta_depth;
	return (EXIT_SUCCESS);
}

void	deal_with_vert_intercept(t_game *g)
{
	int			j;

	if (g->cos_a > 0)
	{
		g->x_vert = g->x_map + 1;
		g->dx = 1;
	}
	else
	{
		g->x_vert = g->x_map - 1e-6;
		g->dx = -1;
	}
	g->depth_vert = (g->x_vert - g->px) / g->cos_a;
	g->y_vert = g->py + g->depth_vert * g->sin_a;
	g->delta_depth = g->dx / g->cos_a;
	g->dy = g->delta_depth * g->sin_a;
	j = -1;
	while (++j < WIDTH * 5)
		if (find_wall_for_vert_line(g))
			break ;
}

void	do_for_each_ray(t_game *g)
{
	g->x_hor = g->px;
	g->y_hor = g->py;
	g->x_vert = g->px;
	g->y_vert = g->py;
	g->sin_a = sin(g->ray_angle);
	g->cos_a = cos(g->ray_angle);
	deal_with_hor_intercept(g);
	deal_with_vert_intercept(g);
}
