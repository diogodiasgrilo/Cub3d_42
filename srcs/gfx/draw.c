/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:10:13 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 14:43:42 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <std.h>
#include <gfx/window.h>
#include "gfx/draw.h"

void	gfx_draw_pixel(t_gfx_image *image, t_vec2 pos, u_int32_t color)
{
	if (!image)
		return ;
	gfx_put_pixel_in_image(image, pos, color, false);
}

static t_vec2	compute_end(t_gfx_line *line)
{
	t_vec2f	direction;

	direction = vec2f_mul_scal(vec2f_normalize(line->direction), line->length);
	return (vec2i(line->start.x + direction.x, line->start.y + direction.y));
}

void	gfx_draw_line(t_gfx_image *image, t_gfx_line line)
{
	t_vec2	end;
	t_vec2	iter;
	t_vec2	delta;
	t_vec2	sign;
	t_vec2	error;

	if (!image)
		return ;
	end = compute_end(&line);
	delta = vec2i(abs(end.x - line.start.x), abs(end.y - line.start.y));
	if (line.start.x < end.x)
		sign.x = 1;
	else
		sign.x = -1;
	if (line.start.y < end.y)
		sign.y = 1;
	else
		sign.y = -1;
	error = vec2i(delta.x - delta.y, 0);
	iter = line.start;
	while (iter.x != end.x || iter.y != end.y)
	{
		gfx_put_pixel_in_image(image, iter, line.color, false);
		if (error.x > 0)
		{
			iter.x += sign.x;
			error.x -= delta.y;
		}
		if (error.y > 0)
		{
			iter.y += sign.y;
			error.y -= delta.x;
		}
		error.x += delta.x;
		error.y += delta.y;
	}
}

void	gfx_draw_rect(t_gfx_image *image, t_gfx_rect rect)
{
	t_vec2	iter;
	t_vec2	end;

	if (!image)
		return ;
	iter = rect.start;
	end = vec2i(rect.start.x + rect.size.x, rect.start.y + rect.size.y);
	while (iter.y < end.y)
	{
		iter.x = rect.start.x;
		while (iter.x < end.x)
		{
			gfx_put_pixel_in_image(image, rect.start, rect.color, false);
			iter.x++;
		}
		iter.y++;
	}
}

void	gfx_draw_circle(t_gfx_image *image, t_gfx_circle circle)
{
	t_vec2	iter;
	t_vec2	end;

	end = vec2i(circle.center.x + circle.radius, \
		circle.center.y + circle.radius);
	iter = vec2i(circle.center.x - circle.radius, \
		circle.center.y - circle.radius);
	while (iter.y < end.y)
	{
		iter.x = circle.center.x - circle.radius;
		while (iter.x < end.x)
		{
			if (vec2i_dist(iter, circle.center) <= circle.radius)
				gfx_put_pixel_in_image(image, iter, circle.color, false);
			iter.x++;
		}
		iter.y++;
	}
}
