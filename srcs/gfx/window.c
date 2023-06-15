/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:25:38 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 18:44:50 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <std.h>
#include <context/context.h>
#include <gfx/support.h>
#include <gfx/image.h>
#include "gfx/window.h"
#include "gfx/window_methods.h"

static void	*window_create(void)
{
	t_gfx_window	*window;

	window = ft_calloc(1, sizeof(t_gfx_window));
	if (!window)
		return (NULL);
	window->clear = __window_clear;
	window->render = __window_render;
	window->setup = __window_setup;
	window->start = __window_start;
	window->hook_new_frame = __window_hook_new_frame;
	window->draw_pixel = __window_draw_pixel;
	window->draw_line = __window_draw_line;
	window->draw_rect = __window_draw_rect;
	window->draw_circle = __window_draw_circle;
	window->draw_image = __window_draw_image;
	window->draw_image_rect = __window_draw_image_rect;
	window->new_image = gfx_new_image;
	window->new_image_from_path = gfx_new_image_from_path;
	window->destroy_image = gfx_destroy_image;
	return (window);
}

static void	window_destroy(t_gfx_window *window)
{
	if (!window)
		return ;
	if (window->render_buffer)
		gfx_destroy_image(window->render_buffer);
	if (window->win)
		mlx_destroy_window(window->mlx, window->win);
	if (window->mlx)
	{
		if (!IS_DARWIN)
			mlx_destroy_display(window->mlx);
		free(window->mlx);
	}
}

t_gfx_window	*get_window(void)
{
	return (get_context(\
		CONTEXT_ID_WINDOW, \
		window_create, \
		(t_context_destruct_fn)window_destroy \
	));
}
