/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:54:08 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 16:57:58 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine/engine.h>
#include "engine/input.h"

static int	__on_key_press(int keycode)
{
	if (keycode < 0 || keycode > INPUT_MAX)
		return (0);
	// ft_printf("keycode: %d pressed\n", keycode);
	engine()->input->keys[keycode] = true;
	return (0);
}

static int	__on_key_release(int keycode)
{
	if (keycode < 0 || keycode >= INPUT_MAX)
		return (0);
	// ft_printf("keycode: %d released\n", keycode);
	engine()->input->keys[keycode] = false;
	return (0);
}

static bool	engine_input_is_pressed(t_engine_input_keycodes keycode)
{
	return (engine()->input->keys[keycode]);
}

static bool	engine_input_is_mouse_moving(void)
{
	return (engine()->input->mouse_delta.x != 0
		|| engine()->input->mouse_delta.y != 0);
}

static void	engine_input_start(void)
{
	t_engine	*e;

	e = engine();
	if (!e || !e->gfx)
		return ;
	mlx_key_hook(e->gfx->win, __on_key_release, NULL);
	mlx_hook(e->gfx->win, 2, 1L << 0, __on_key_press, NULL);
}

static void	engine_input_update(double delta_time)
{
	t_engine		*e;
	t_engine_input	*input;

	(void)delta_time;
	e = engine();
	input = e->input;
	input->mouse_delta = vec2i_sub(input->mouse_pos, input->last_mouse_pos);
	input->last_mouse_pos = input->mouse_pos;
	mlx_mouse_get_pos(e->gfx->mlx, e->gfx->win, &input->mouse_pos.x,
		&input->mouse_pos.y);
}

static void	engine_input_set_mouse_pos(t_vec2 pos)
{
	t_engine	*e;

	e = engine();
	e->input->last_mouse_pos = pos;
	mlx_mouse_move(e->gfx->mlx, e->gfx->win, pos.x, pos.y);
	e->input->mouse_pos = pos;
}

static void	engine_input_hide_mouse(void)
{
	t_engine	*e;

	e = engine();
	mlx_mouse_hide(e->gfx->mlx, e->gfx->win);
}

static void	engine_input_show_mouse(void)
{
	t_engine	*e;

	e = engine();
	mlx_mouse_show(e->gfx->mlx, e->gfx->win);
}

t_engine_input	*engine_input_init(void)
{
	static t_engine_input	input;

	input.is_pressed = engine_input_is_pressed;
	input.is_mouse_moving = engine_input_is_mouse_moving;
	input.set_mouse_pos = engine_input_set_mouse_pos;
	input.hide_mouse = engine_input_hide_mouse;
	input.show_mouse = engine_input_show_mouse;
	input.start = engine_input_start;
	input.update = engine_input_update;
	return (&input);
}
