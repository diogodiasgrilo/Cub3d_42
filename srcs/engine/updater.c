/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:33:04 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 18:05:54 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"
#include <utils/time.h>
#include <oop/oop.h>

int	__engine_on_new_frame(void)
{
	static double	last_frame;
	double			delta_time;
	double			time;

	time = now();
	delta_time = time - last_frame;
	last_frame = time;
	engine()->delta_time = delta_time;
	engine()->input->update(delta_time);
	engine()->update(delta_time);
	engine()->render(delta_time);
	return (0);
}

void	__engine_update(double delta_time)
{
	t_engine		*e;
	t_list			*iter;
	t_object		*obj;
	// static t_vec2	pos = { 400, 300 };
	// static double	angle;

	e = engine();
	if (!e || !e->gfx->focused)
		return ;

	t_vec3f	*acceleration = &pthis()->get_physics()->acceleration;

	if (e->input->is_pressed(INPUT_KEYCODE_A))
		acceleration->x = -0.001f * delta_time;
	if (e->input->is_pressed(INPUT_KEYCODE_D))
		acceleration->x = 0.001F * delta_time;
	if (e->input->is_pressed(INPUT_KEYCODE_W))
		acceleration->y = 0.001f * delta_time;
	if (e->input->is_pressed(INPUT_KEYCODE_S))
		acceleration->y = -0.001 * delta_time;
	if (e->input->is_pressed(INPUT_KEYCODE_ARROW_RIGHT))
		pthis()->get_transform()->rotation += (0.001f * delta_time);
	else if (e->input->is_pressed(INPUT_KEYCODE_ARROW_LEFT))
		pthis()->get_transform()->rotation -= (0.001f * delta_time);
	if (pthis()->transform->rotation > 2 * PI)
		pthis()->get_transform()->rotation -= 2 * PI;
	else if (pthis()->transform->rotation < 0)
		pthis()->get_transform()->rotation += 2 * PI;

	iter = e->objects;
	while (iter)
	{
		obj = iter->content;
		if (obj->update)
		{
			oop()->push(obj);
			obj->update(delta_time);
			oop()->pop(obj);
		}
		iter = iter->next;
	}
	/* ft_printf("Player pos: (%f, %f, %f) angle: %f\n", \
		pthis()->get_position()->x, \
		pthis()->get_position()->y, \
		pthis()->get_position()->z, \
		*pthis()->get_rotation() * 180 / PI
	); */
}

void	__engine_render(double delta_time)
{
	t_engine	*e;
	t_object	*obj;
	t_list		*iter;

	e = engine();
	if (!e || !e->gfx->focused)
		return ;
	iter = e->objects;
	e->input->hide_mouse();
	e->gfx->clear(false);
	while (iter)
	{
		obj = iter->content;
		if (obj->render)
		{
			oop()->push(obj);
			obj->render(delta_time);
			oop()->pop(obj);
		}
		iter = iter->next;
	}
	e->gfx->render();
}
