/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:48:30 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/14 17:07:19 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

int positive_modulo(int i, int n) {
    return (i % n + n) % n;
}

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
            sky_x = positive_modulo((int)(x + g->sky_offset_x), g->textures->sky->width);
            sky_y = y * g->textures->sky->height / (HEIGHT / 1.5);
            color = *(int*)(g->textures->sky->data + sky_y * g->textures->sky->size_line + sky_x * g->textures->sky->bpp / 8);
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
            color = *(int*)(gun_data + y * g->textures->portal_gun->size_line + x * g->textures->portal_gun->bpp / 8);
            if (!(color >> 24 & 0xFF))
            {
                my_mlx_pixel_put(&g->scene, x_start + x, y_start + y, color);
            }
        }
    }
}

void	*create_floor(t_game *g, t_put_on_screen proj, int i)
{
	t_image_creator	ic;
	
	// ic.y = 0;
	// while (ic.y <= (proj.y - proj.proj_height) + 3)
	// {
	// 	ic.x = 0;
	// 	put_pixel(&g->scene, i, ic.y, BLUEGREY);
	// 	ic.y++;
	// }
	ic.y = HEIGHT;
	while (ic.y >= proj.y - 3)
	{
		ic.x = 0;
		put_pixel(&g->scene, i, ic.y, NEWGREY);
		ic.y--;
	}
	return (ic.img);
}

void	init_textures(t_game *g)
{
	g->textures->piping = (t_texture *)malloc(sizeof(t_texture));
	g->textures->vwall = (t_texture *)malloc(sizeof(t_texture));
	g->textures->gate = (t_texture *)malloc(sizeof(t_texture));
	g->textures->port = (t_texture *)malloc(sizeof(t_texture));
	g->textures->sky = (t_texture *)malloc(sizeof(t_texture));
	g->textures->portal_gun = (t_texture *)malloc(sizeof(t_texture));
}

void	load_textures(t_game *g)
{	
	init_textures(g);
	g->textures->portal_gun->img = mlx_xpm_file_to_image(g->id, \
		"./resources/textures/portal_gun.xpm", &g->textures->portal_gun->width, &g->textures->portal_gun->height);
	g->textures->portal_gun->data = mlx_get_data_addr(g->textures->portal_gun->img, &g->textures->portal_gun->bpp, &g->textures->portal_gun->size_line, &g->textures->portal_gun->endian);
	g->textures->sky->img = mlx_xpm_file_to_image(g->id, \
		"./resources/textures/planet_sky.xpm", &g->textures->sky->width, &g->textures->sky->height);
	g->textures->sky->data = mlx_get_data_addr(g->textures->sky->img, &g->textures->sky->bpp, &g->textures->sky->size_line, &g->textures->sky->endian);
	g->textures->piping->img = mlx_xpm_file_to_image(g->id, \
		"./resources/textures/piping.xpm", &g->textures->piping->width, &g->textures->piping->height);
	g->textures->piping->data = mlx_get_data_addr(g->textures->piping->img, &g->textures->piping->bpp, &g->textures->piping->size_line, &g->textures->piping->endian);
	g->textures->vwall->img = mlx_xpm_file_to_image(g->id, \
		"./resources/textures/vwall.xpm", &g->textures->vwall->width, &g->textures->vwall->height);
	g->textures->vwall->data = mlx_get_data_addr(g->textures->vwall->img, &g->textures->vwall->bpp, &g->textures->vwall->size_line, &g->textures->vwall->endian);
	g->textures->gate->img = mlx_xpm_file_to_image(g->id, \
		"./resources/textures/gate.xpm", &g->textures->gate->width, &g->textures->gate->height);
	g->textures->gate->data = mlx_get_data_addr(g->textures->gate->img, &g->textures->gate->bpp, &g->textures->gate->size_line, &g->textures->gate->endian);
	g->textures->port->img = mlx_xpm_file_to_image(g->id, \
		"./resources/textures/port.xpm", &g->textures->port->width, &g->textures->port->height);
	g->textures->port->data = mlx_get_data_addr(g->textures->port->img, &g->textures->port->bpp, &g->textures->port->size_line, &g->textures->port->endian);
	return ;
}