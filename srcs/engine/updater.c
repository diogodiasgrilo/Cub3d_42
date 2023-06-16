/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:33:04 by martiper          #+#    #+#             */
/*   Updated: 2023/06/16 16:43:18 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"
#include <utils/time.h>

int	__engine_on_new_frame(void)
{
	static double	last_frame;
	double			delta_time;
	double			time;

	time = now();
	delta_time = time - last_frame;
	last_frame = time;
	engine()->input->update(delta_time);
	engine()->update(delta_time);
	return (0);
}

void	__engine_update(double delta_time)
{
	t_engine		*e;
	static t_vec2	pos = { 400, 300 };
	static double	angle;

	e = engine();
	if (!e || !e->gfx->focused)
		return ;

	if (e->input->is_pressed(INPUT_KEYCODE_A))
		pos.x -= (int)ceil(0.1 * delta_time);
	if (e->input->is_pressed(INPUT_KEYCODE_D))
		pos.x += (int)ceil(0.1 * delta_time);
	if (e->input->is_pressed(INPUT_KEYCODE_W))
		pos.y -= (int)ceil(0.1 * delta_time);
	if (e->input->is_pressed(INPUT_KEYCODE_S))
		pos.y += (int)ceil(0.1 * delta_time);
	pos = vec2i_clamp(pos, vec2i(0,0), e->gfx->size);
	if (e->input->mouse_pos.x < 100 || e->input->mouse_pos.x > 700)
		e->input->set_mouse_pos(vec2i(400, 300));
	angle += e->input->mouse_delta.x * 0.0005 * delta_time;
	angle = fmod(angle, 2 * M_PI);
	e->gfx->clear(false);
	/* e->gfx->draw_circle((t_gfx_circle){
		.center = pos,
		.radius = 20 + 10 * sin(angle) * cos(angle),
		.color = 0xFFFFFFFF
	}); */
	t_vec2	size = vec2i(20 + 10 * sin(angle), 20 + 10 * sin(angle));
	e->gfx->draw_rect((t_gfx_rect){
		.start = vec2i_sub(pos, vec2i_div_scal(size, 2)),
		.size = size,
		.color = 0xFFFFFFFF,
		.fill = false
	});
	e->gfx->draw_line((t_gfx_line){
		.start = pos,
		.direction = vec2f(cos(angle), sin(angle)),
		.color = 0xFFFF0000,
		.length = 45.0
	});
	e->input->hide_mouse();
	e->gfx->render();
}
