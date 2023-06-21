/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:48:30 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 19:43:40 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void	init_textures(t_game *g)
{
	g->textures->north = (t_texture *)malloc(sizeof(t_texture));
	g->textures->south = (t_texture *)malloc(sizeof(t_texture));
	g->textures->east = (t_texture *)malloc(sizeof(t_texture));
	g->textures->west = (t_texture *)malloc(sizeof(t_texture));
	g->textures->sky = (t_texture *)malloc(sizeof(t_texture));
	g->textures->portal_gun = (t_texture *)malloc(sizeof(t_texture));
	if (!g->textures->north || !g->textures->south || !g->textures->east || \
		!g->textures->west || !g->textures->sky || !g->textures->portal_gun)
	{
		destroy_all_mlx_images();
		exit(1);
	}
}

void	load_wall_textures(t_game *g, t_map_errors *parsed)
{
	g->textures->north->img = mlx_xpm_file_to_image(g->id, \
		parsed->north_texture, &g->textures->north->width, \
		&g->textures->north->height);
	g->textures->north->data = mlx_get_data_addr(g->textures->north->img, \
		&g->textures->north->bpp, &g->textures->north->size_line, \
		&g->textures->north->endian);
	g->textures->south->img = mlx_xpm_file_to_image(g->id, \
		parsed->south_texture, &g->textures->south->width, \
		&g->textures->south->height);
	g->textures->south->data = mlx_get_data_addr(g->textures->south->img, \
		&g->textures->south->bpp, &g->textures->south->size_line, \
		&g->textures->south->endian);
	g->textures->east->img = mlx_xpm_file_to_image(g->id, \
		parsed->east_texture, &g->textures->east->width, \
		&g->textures->east->height);
	g->textures->east->data = mlx_get_data_addr(g->textures->east->img, \
		&g->textures->east->bpp, &g->textures->east->size_line, \
		&g->textures->east->endian);
	g->textures->west->img = mlx_xpm_file_to_image(g->id, \
		parsed->west_texture, &g->textures->west->width, \
		&g->textures->west->height);
	g->textures->west->data = mlx_get_data_addr(g->textures->west->img, \
		&g->textures->west->bpp, &g->textures->west->size_line, \
		&g->textures->west->endian);
}

void	load_textures(t_game *g, t_map_errors *parsed)
{
	init_textures(g);
	g->textures->portal_gun->img = mlx_xpm_file_to_image(g->id, \
		"./resources/textures/portal_gun.xpm", &g->textures->portal_gun->width, \
		&g->textures->portal_gun->height);
	g->textures->portal_gun->data = \
		mlx_get_data_addr(g->textures->portal_gun->img, \
		&g->textures->portal_gun->bpp, &g->textures->portal_gun->size_line, \
		&g->textures->portal_gun->endian);
	g->textures->sky->img = mlx_xpm_file_to_image(g->id, \
		"./resources/textures/planet_sky.xpm", &g->textures->sky->width, \
		&g->textures->sky->height);
	g->textures->sky->data = mlx_get_data_addr(g->textures->sky->img, \
		&g->textures->sky->bpp, &g->textures->sky->size_line, \
		&g->textures->sky->endian);
	load_wall_textures(g, parsed);
	return ;
}
