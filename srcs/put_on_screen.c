/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_on_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:18:47 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/09 18:38:48 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void    determine_color (t_put_on_screen        *sc)
{
	t_determine_color dc;
	
    dc.max_distance = 0.0f;
    dc.min_distance = 200.0f;
    dc.height = 0.0f;

    sc->color = 0xFFFFFF;
    if (sc->proj_height > dc.min_distance) {
        dc.height = dc.min_distance;
    } else if (sc->proj_height < dc.max_distance) {
        dc.height = dc.max_distance;
    }
    else
        dc.height = sc->proj_height;
    dc.ratio = (dc.height - dc.min_distance) / (dc.max_distance - dc.min_distance);
    dc.white = 0xFFFFFF;
    dc.grey = 0x808080;
    dc.red = (int)(((dc.white >> 16) & 0xFF) * (1.0f - dc.ratio) + ((dc.grey >> 16) & 0xFF) * dc.ratio);
    dc.green = (int)(((dc.white >> 8) & 0xFF) * (1.0f - dc.ratio) + ((dc.grey >> 8) & 0xFF) * dc.ratio);
    dc.blue = (int)((dc.white & 0xFF) * (1.0f - dc.ratio) + (dc.grey & 0xFF) * dc.ratio);
    sc->color = (dc.red << 16) | (dc.green << 8) | dc.blue;
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