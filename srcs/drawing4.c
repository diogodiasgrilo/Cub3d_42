/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:29:23 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/22 11:16:47 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	*get_pixel_address(t_image_creator *image, int x, int y)
{
	return ((void *)(\
		image->data + \
		((y * image->size_line) + \
		(x * (image->bpp / 8)) \
	)));
}

void	put_pixel(t_image_creator *image, int x, int y, int color)
{
	void	*pixel;

	if (\
		x < 0 || x >= image->width || \
		y < 0 || y >= image->height \
	)
		return ;
	pixel = get_pixel_address(image, x, y);
	*(unsigned int *)pixel = color;
}

int	draw_line_loop(t_gfx_line line, t_line_drawing *rs)
{
	put_pixel(line.buffer, rs->x1, rs->y1, line.color);
	if (rs->x1 == rs->x2 && rs->y1 == rs->y2)
		return (EXIT_SUCCESS);
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
	return (EXIT_FAILURE);
}

void	draw_line(t_gfx_line line)
{
	t_line_drawing	rs;

	rs.x1 = line.start_x;
	rs.y1 = line.start_y;
	rs.x2 = line.start_x + line.direction_x * line.length;
	rs.y2 = line.start_y + line.direction_y * line.length;
	rs.dx = abs(rs.x2 - rs.x1);
	rs.dy = -abs(rs.y2 - rs.y1);
	rs.err = rs.dx + rs.dy;
	if (rs.x1 < rs.x2)
		rs.sx = 1;
	else
		rs.sx = -1;
	if (rs.y1 < rs.y2)
		rs.sy = 1;
	else
		rs.sy = -1;
	while (1)
		if (!draw_line_loop(line, &rs))
			break ;
}
