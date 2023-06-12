/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:24:47 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 14:52:28 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/sprites/store.h"
#include <context/context.h>

static void	*sprite_store_create(void)
{
	return (ft_lstnew(NULL));
}

static void	sprite_store_destroy(t_sl_sprite_store *registry)
{
	ft_lstclear(&registry, (void (*)(void *))sl_free_sprite);
}

t_sl_sprite_store	*get_sprite_store_ctx(void)
{
	return (get_context(\
		CONTEXT_ID_SPRITE_STORE, \
		sprite_store_create, \
		(void (*)(void *))sprite_store_destroy \
	));
}

t_sl_sprite	*sl_get_sprite(char *path)
{
	t_sl_sprite_store	*store;
	t_list				*node;
	t_sl_sprite			*sprite;

	store = get_sprite_store_ctx();
	node = store->next;
	while (node)
	{
		sprite = node->content;
		if (ft_strcmp(sprite->path, path) == 0)
			return (sprite);
		node = node->next;
	}
	return (NULL);
}
