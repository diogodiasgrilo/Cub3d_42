/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:50:42 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 16:47:07 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <context/context.h>
#include <std.h>
#include "engine/engine.h"

int		__engine_on_new_frame(void);
void	__engine_update(double delta_time);
void	__engine_render(double delta_time);


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

static t_object	*__engine_get_object(u_int32_t id)
{
	t_list		*iter;
	t_object	*obj;

	iter = engine()->objects;
	while (iter)
	{
		obj = iter->content;
		if (obj->get_identity()->id == id)
			return (obj);
		iter = iter->next;
	}
	return (NULL);
}

static t_object	*__engine_get_object_by_tag(char *tag)
{
	t_list		*iter;
	t_object	*obj;

	iter = engine()->objects;
	while (iter)
	{
		obj = iter->content;
		if (ft_strcmp(obj->tag, tag) == 0)
			return (obj);
		iter = iter->next;
	}
	return (NULL);
}

static bool	__engine_add_object(t_object *obj)
{
	t_list		*new;

	if (!obj)
		return (false);
	new = ft_lstnew(obj);
	if (!new)
		return (false);
	ft_lstadd_back(&engine()->objects, new);
	return (true);
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
	engine->parser = get_parser();
	engine->materials = get_materials();
	engine->init = __engine_init;
	engine->start = __engine_start;
	engine->update = __engine_update;
	engine->render = __engine_render;
	engine->get_object = __engine_get_object;
	engine->get_object_by_tag = __engine_get_object_by_tag;
	engine->add_object = __engine_add_object;
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
