/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:14:35 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 16:23:38 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine/engine.h>
#include "engine/sprites/sprite.h"
#include <utils/log.h>

void	engine_sprites_free_sprite(t_engine_sprite *sprite)
{
	if (!sprite)
		return (logger()->error("Attempted to free NULL sprite, how?"));
	logger()->info("Cleaning up sprite at path: %s", sprite->path);
	if (sprite->asset)
		engine()->gfx->destroy_image(sprite->asset);
	if (sprite->path)
		free(sprite->path);
	free(sprite);
}

/* static void	add_sprite_to_store(t_list **store, t_engine_sprite *sprite)
{
	t_list	*node;

	if ((*store) && (*store)->content == NULL)
		(*store)->content = sprite;
	else
	{
		node = ft_lstnew(sprite);
		if (!node)
		{
			sl_free_sprite(sprite);
			return ;
		}
		ft_lstadd_back(store, node);
	}
} */

// TODO: SPRITE SCALING
t_engine_sprite	*engine_sprites_load_sprite_from_disk(char *path)
{
	t_engine_sprite	*sprite;

	sprite = ft_calloc(1, sizeof(t_engine_sprite));
	if (!sprite)
		return (NULL);
	sprite->path = ft_strdup(path);
	sprite->asset = engine()->gfx->new_image_from_path(path);
	if (!sprite->asset)
		return (free(sprite->path), free(sprite), NULL);
	sprite->size = vec2i(sprite->asset->width, sprite->asset->height);
	sprite->ratio = (double)sprite->size.x / (double)sprite->size.y;
	return (sprite);
}
