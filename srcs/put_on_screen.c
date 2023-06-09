/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_on_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:18:47 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/09 18:33:35 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void    determine_color (t_put_on_screen        *sc)
{
    float max_distance = 0.0f;
    float min_distance = 200.0f;
    float height = 0.0f;

    sc->color = 0xFFFFFF;
    if (sc->proj_height > min_distance) {
        height = min_distance;
    } else if (sc->proj_height < max_distance) {
        height = max_distance;
    }
    else
        height = sc->proj_height;
    float ratio = (height - min_distance) / (max_distance - min_distance);
    int white = 0xFFFFFF;
    int grey = 0x808080;
    int red = (int)(((white >> 16) & 0xFF) * (1.0f - ratio) + ((grey >> 16) & 0xFF) * ratio);
    int green = (int)(((white >> 8) & 0xFF) * (1.0f - ratio) + ((grey >> 8) & 0xFF) * ratio);
    int blue = (int)((white & 0xFF) * (1.0f - ratio) + (grey & 0xFF) * ratio);
    sc->color = (red << 16) | (green << 8) | blue;
}

void	put_on_screen(t_game *g, t_line_drawing *rs, float ray_angle, int ray)
{	
    t_put_on_screen        sc;
    
	sc.starting_x = rs->x1;
	sc.starting_y = rs->y1;
	while (1)
	{
		my_mlx_pixel_put(&g->map_buffer, rs->x1, rs->y1, NEWWHITE);
		if (g->map[(rs->y1 + 1) / MAP_SIZE][(rs->x1 + 1) / MAP_SIZE] == '1')
			break ;
		rs->e2 = 2 * rs->err;
		if (rs->e2 >= rs->dy)
		{
			rs->err += rs->dy;
			rs->x1 += rs->sx;
		}
		if (rs->e2 <= rs->dx)
		{
			rs->err += rs->dx;
			rs->y1 += rs->sy;
		}
	}
	sc.distance = sqrt(pow((rs->x1 - sc.starting_x), 2) + pow((rs->y1 - sc.starting_y), 2));
	sc.distance *= cos(g->pa - ray_angle);
	sc.proj_height = (SCREEN_DIST / (sc.distance + 0.0001)) * WALL_HEIGHT;
    determine_color (&sc);
    sc.y = -1;
    while (++sc.y < sc.proj_height)
	{
		my_mlx_pixel_put(&g->scene,(ray * SCALE), sc.y + floor(HALF_HEIGHT - sc.proj_height / 2), sc.color);
		my_mlx_pixel_put(&g->scene,(ray * SCALE) + 1, sc.y + floor(HALF_HEIGHT - sc.proj_height / 2), sc.color);
	}
    g->prev_height = sc.proj_height;
}