/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:48:30 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/20 21:00:33 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void put_sky(t_game *g) 
{
    int y;
    int x;
    int sky_x;
    int sky_y;
    int color;

    y = -1;
    while (++y < HEIGHT / 2) 
    { 
        x = -1;
        while (++x < WIDTH) 
        {
            sky_x = ((int)(x + g->sky_offset_x) % g->textures->sky->width \
				+ g->textures->sky->width) % g->textures->sky->width;
            sky_y = y * g->textures->sky->height / (HEIGHT / 1.5);
            color = *(int*)(g->textures->sky->data + sky_y * \
				g->textures->sky->size_line + sky_x * g->textures->sky->bpp / 8);
            my_mlx_pixel_put(&g->scene, x, y, color);
        }
    }
}

void put_portal_gun(t_game *g)
{
    int gun_width;
    int gun_height;
    int x_start, y_start;
    int x, y;
    int color;
    char *gun_data = g->textures->portal_gun->data;

    gun_width = g->textures->portal_gun->width;
    gun_height = g->textures->portal_gun->height;
    x_start = WIDTH - gun_width / 1.7;
    y_start = HEIGHT - gun_height / 1.1;
    y = -1;
    while (++y < gun_height)
    {
        x = -1;
        while (++x < gun_width)
        {
            color = *(int*)(gun_data + y * g->textures->portal_gun->size_line \
				+ x * g->textures->portal_gun->bpp / 8);
            if (!(color >> 24 & 0xFF))
                my_mlx_pixel_put(&g->scene, x_start + x, y_start + y, color);
        }
    }
}

void	*create_floor_sky(t_game *g, t_put_on_screen proj, int i)
{
	t_image_creator	ic;
	
	ic.y = 0;
	// UN-COMMENT TO CREATE THE CEILING COLOR IN FILE
	while (ic.y <= (proj.y - proj.proj_height) + 3)
	{
		ic.x = 0;
		put_pixel(&g->scene, i, ic.y, g->parsed->ceiling_color);
		ic.y++;
	}
	ic.y = HEIGHT;
	while (ic.y >= proj.y - 3)
	{
		ic.x = 0;
		put_pixel(&g->scene, i, ic.y, g->parsed->floor_color);
		ic.y--;
	}
	return (ic.img);
}

void	init_textures(t_game *g)
{
	g->textures->north = (t_texture *)malloc(sizeof(t_texture));
	g->textures->south = (t_texture *)malloc(sizeof(t_texture));
	g->textures->east = (t_texture *)malloc(sizeof(t_texture));
	g->textures->west = (t_texture *)malloc(sizeof(t_texture));
	g->textures->sky = (t_texture *)malloc(sizeof(t_texture));
	g->textures->portal_gun = (t_texture *)malloc(sizeof(t_texture));
}

void	load_textures(t_game *g, t_map_errors *parsed)
{	
	init_textures(g);
	g->textures->portal_gun->img = mlx_xpm_file_to_image(g->id, \
		"./resources/textures/portal_gun.xpm", &g->textures->portal_gun->width, &g->textures->portal_gun->height);
	g->textures->portal_gun->data = mlx_get_data_addr(g->textures->portal_gun->img, &g->textures->portal_gun->bpp, &g->textures->portal_gun->size_line, &g->textures->portal_gun->endian);
	g->textures->sky->img = mlx_xpm_file_to_image(g->id, \
		"./resources/textures/planet_sky.xpm", &g->textures->sky->width, &g->textures->sky->height);
	g->textures->sky->data = mlx_get_data_addr(g->textures->sky->img, &g->textures->sky->bpp, &g->textures->sky->size_line, &g->textures->sky->endian);
	g->textures->north->img = mlx_xpm_file_to_image(g->id, \
		parsed->north_texture, &g->textures->north->width, &g->textures->north->height);
	g->textures->north->data = mlx_get_data_addr(g->textures->north->img, &g->textures->north->bpp, &g->textures->north->size_line, &g->textures->north->endian);
	g->textures->south->img = mlx_xpm_file_to_image(g->id, \
		parsed->south_texture, &g->textures->south->width, &g->textures->south->height);
	g->textures->south->data = mlx_get_data_addr(g->textures->south->img, &g->textures->south->bpp, &g->textures->south->size_line, &g->textures->south->endian);
	g->textures->east->img = mlx_xpm_file_to_image(g->id, \
		parsed->east_texture, &g->textures->east->width, &g->textures->east->height);
	g->textures->east->data = mlx_get_data_addr(g->textures->east->img, &g->textures->east->bpp, &g->textures->east->size_line, &g->textures->east->endian);
	g->textures->west->img = mlx_xpm_file_to_image(g->id, \
		parsed->west_texture, &g->textures->west->width, &g->textures->west->height);
	g->textures->west->data = mlx_get_data_addr(g->textures->west->img, &g->textures->west->bpp, &g->textures->west->size_line, &g->textures->west->endian);
	return ;
}