/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_on_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:18:47 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/08 13:04:13 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void    determine_color (t_put_on_screen        *sc)
{
    float max_distance = 0.0f;
    float min_distance = 600.0f;
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

void	put_on_screen(t_game *g, t_line_drawing *rs, int *column_n, float ray_angle)
{	
    t_put_on_screen        sc;
    
	sc.starting_x = rs->x1;
	sc.starting_y = rs->y1;
	while (1)
	{
		my_mlx_pixel_put(&g->map_buffer, rs->x1, rs->y1, NEWWHITE);
		if (g->map[rs->y1 / MAP_SIZE][rs->x1 / MAP_SIZE] == '1')
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
	sc.half_width = (int)WIDTH / 2;  
	sc.half_height = (int)HEIGHT / 2;
	sc.screen_dis = sc.half_width / tan(RAY_ANGLE / 2);
	sc.proj_height = (float)(sc.screen_dis / (sc.distance + 0.0001) * SIZE);
	sc.scale = (int)(WIDTH) / (RAY_ANGLE);
    determine_color (&sc);
    sc.y = -1;
    while (++sc.y < sc.proj_height)
        my_mlx_pixel_put(&g->scene,((*column_n / (N_RAYS_PER_ANGLE)) * sc.scale), sc.y + sc.half_height - (int)(sc.proj_height / 2.0), sc.color);
    *column_n += 1;
    g->prev_height = sc.proj_height;
}