/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:33:04 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 18:49:38 by martiper         ###   ########.fr       */
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
	engine()->update(delta_time);
	return (0);
}

void	__engine_update(double delta_time)
{
	t_engine		*e;
	static double	i;

	e = engine();
	e->gfx->clear(false);
	i += delta_time / 500.0;
	if (i >= 2 * M_PI)
		i = 0;
	e->gfx->draw_circle((t_gfx_circle){
		.center = vec2i(400, 300),
		.radius = 20 + 10 * sin(i) * cos(i),
		.color = 0xFFFFFFFF
	});
	e->gfx->draw_line((t_gfx_line){
		.start = vec2i(400, 300),
		.direction = vec2f(cos(i), sin(i)),
		.color = 0xFFFF0000,
		.length = 45.0
	});
	e->gfx->render();
}
