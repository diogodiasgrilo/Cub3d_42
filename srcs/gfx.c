/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:39:01 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 03:06:00 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

static void	*get_pixel_address(t_mlx_image *image, t_vec2 pos)
{
	return ((void *)(\
		image->data + \
		((pos.y * image->size_line) + \
		(pos.x * (image->bpp / 8)) \
	)));
}

static void	put_pixel(t_mlx_image *image, t_vec2 pos, int color)
{
	void	*pixel;

	if (\
		pos.x < 0 || pos.x >= image->width || \
		pos.y < 0 || pos.y >= image->height \
	)
		return ;
	pixel = get_pixel_address(image, pos);
	*(unsigned int *)pixel = color;
}

/*
	** Draw a line on the image buffer.
	** The line is drawn from start to end.
	** The line is drawn with the color specified.
	** The line has a specified thickness.
 */
void	gfx_draw_line(t_gfx_line line)
{
	t_vec2f	end;
	t_vec2	iter;
	t_vec2	dir;

	line.direction = vec2f_normalize(line.direction);
	dir = vec2i((int)line.direction.x, (int)line.direction.y);
	end = vec2f_add(line.start, vec2f_mul_scal(line.direction, line.length));
	end = vec2f_clamp(end, vec2f(0, 0), vec2f(line.buffer->width, line.buffer->height));
	iter = vec2i((int)line.start.x, (int)line.start.y);
	while (iter.x != (int)end.x)
	{
		iter.y = line.start.y + (dir.y * (iter.x - line.start.x)) / dir.x;
		put_pixel(line.buffer, iter, line.color);
		iter.x += (dir.x > 0) - (dir.x < 0);
	}
}
