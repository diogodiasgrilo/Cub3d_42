/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:45:13 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 18:44:32 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <std.h>
#include "gfx/window_methods.h"

void	__window_clear(bool draw)
{
	t_gfx_window	*window;

	window = get_window();
	if (!window || !window->mlx || !window->win || !window->render_buffer)
		return ;
	gfx_clear_image(window->render_buffer);
	if (draw)
		window->render();
}

void	__window_render(void)
{
	t_gfx_window	*window;

	window = get_window();
	if (!window || !window->mlx || !window->win || !window->render_buffer)
		return ;
	mlx_put_image_to_window(\
		window->mlx, window->win, \
		window->render_buffer->img, 0, 0 \
	);
}

bool	__window_setup(t_vec2 size, char *title)
{
	t_gfx_window	*window;

	window = get_window();
	if (!window)
		return (false);
	if (window->win)
		return (window);
	window->mlx = mlx_init();
	if (!window->mlx)
		return (false);
	window->size = size;
	window->win = mlx_new_window(window->mlx, size.x, size.y, title);
	if (!window->win)
		return (false);
	window->render_buffer = gfx_new_image(size.x, size.y);
	if (!window->render_buffer)
		return (false);
	return (true);
}

void	__window_start(void)
{
	t_gfx_window	*window;

	window = get_window();
	if (!window || !window->mlx || !window->win || \
		!window->render_buffer || window->started)
		return ;
	window->started = true;
	mlx_loop(window->mlx);
}

void	__window_hook_new_frame(int (*f)(void))
{
	t_gfx_window	*window;

	window = get_window();
	if (!window || !window->mlx || !window->win || \
		!window->render_buffer || window->started)
		return ;
	mlx_loop_hook(window->mlx, f, NULL);
}
