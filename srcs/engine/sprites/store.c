/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:24:47 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 17:43:42 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/sprites/store.h"
#include <context/context.h>

t_engine_sprites_store_renderer	*__engine_sprites_get_renderer(void);

static t_engine_sprite	*__get(char *path)
{
	t_engine_sprites_store	*store;
	t_list					*node;
	t_engine_sprite			*sprite;

	store = engine_sprites_get_store();
	node = store->list;
	while (node)
	{
		sprite = node->content;
		if (ft_strcmp(sprite->path, path) == 0)
			return (sprite);
		node = node->next;
	}
	sprite = engine_sprites_load_sprite_from_disk(path);
	if (sprite)
	{
		node = ft_lstnew(sprite);
		if (!node)
			return (engine_sprites_free_sprite(sprite), NULL);
		ft_lstadd_back(&store->list, node);
	}
	return (sprite);
}

static void	*sprites_store_create(void)
{
	t_engine_sprites_store	*store;

	store = ft_calloc(1, sizeof(t_engine_sprites_store));
	if (!store)
		return (NULL);
	store->list = NULL;
	store->renderer = __engine_sprites_get_renderer();
	store->get = __get;
	return (store);
}

static void	sprites_store_destroy(t_engine_sprites_store *store)
{
	if (!store)
		return ;
	ft_lstclear(&store->list, (void (*)(void *))engine_sprites_free_sprite);
	free(store);
}

t_engine_sprites_store	*engine_sprites_get_store(void)
{
	return (get_context(\
		CONTEXT_ID_SPRITES_STORE, \
		sprites_store_create, \
		(t_context_destruct_fn)sprites_store_destroy \
	));
}
