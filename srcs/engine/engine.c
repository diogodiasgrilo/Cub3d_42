/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:50:42 by martiper          #+#    #+#             */
/*   Updated: 2023/06/16 14:06:51 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <context/context.h>
#include <std.h>
#include "engine/engine.h"

int		__engine_on_new_frame(void);
void	__engine_update(double delta_time);

static bool	__engine_init(char *title, t_vec2 size)
{
	t_engine	*e;

	e = engine();
	if (!e || !e->gfx)
		return (false);
	if (!e->gfx->setup(size, title))
		return (false);
	return (true);
}

static void	__engine_start(void)
{
	t_engine	*e;

	e = engine();
	if (!e || !e->gfx)
		return ;
	e->input->start();
	e->gfx->hook_new_frame(__engine_on_new_frame);
	e->gfx->start();
}

static void	*engine_create(void)
{
	t_engine	*engine;

	engine = ft_calloc(1, sizeof(t_engine));
	if (!engine)
		return (NULL);
	engine->gfx = get_window();
	engine->assets = engine_sprites_get_store();
	engine->input = engine_input_init();
	engine->init = __engine_init;
	engine->start = __engine_start;
	engine->update = __engine_update;
	return (engine);
}

static void	engine_destroy(t_engine *engine)
{
	if (!engine)
		return ;
	free(engine);
}

t_engine	*engine(void)
{
	return (get_context(\
		CONTEXT_ID_ENGINE, \
		engine_create, \
		(t_context_destruct_fn)engine_destroy \
	));
}
