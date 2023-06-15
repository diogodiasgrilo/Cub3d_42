/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_methods2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:48:54 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 17:58:30 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <std.h>
#include "gfx/window_methods.h"

void	__window_draw_pixel(t_vec2 pos, u_int32_t color)
{
	t_gfx_window	*window;

	window = get_window();
	if (!window || !window->render_buffer)
		return ;
	gfx_put_pixel_in_image(window->render_buffer, pos, color, false);
}

void	__window_draw_line(t_gfx_line line)
{
	t_gfx_window	*window;

	window = get_window();
	if (!window || !window->render_buffer)
		return ;
	gfx_draw_line(window->render_buffer, line);
}

void	__window_draw_rect(t_gfx_rect rect)
{
	t_gfx_window	*window;

	window = get_window();
	if (!window || !window->render_buffer)
		return ;
	gfx_draw_rect(window->render_buffer, rect);
}

void	__window_draw_circle(t_gfx_circle circle)
{
	t_gfx_window	*window;

	window = get_window();
	if (!window || !window->render_buffer)
		return ;
	gfx_draw_circle(window->render_buffer, circle);
}

void	__window_draw_image(t_gfx_image *image, t_vec2 pos)
{
	t_gfx_window	*window;

	window = get_window();
	if (!window || !window->render_buffer || !image || !image->img)
		return ;
	gfx_draw_image(window->render_buffer, image, pos);
}

void	__window_draw_image_rect(t_gfx_image *image, t_vec2 pos, t_gfx_rect rect)
{
	t_gfx_window	*window;

	window = get_window();
	if (!window || !window->render_buffer || !image || !image->img)
		return ;
	gfx_draw_image_rect(window->render_buffer, image, pos, rect);
}
