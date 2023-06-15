/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:33:22 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 17:57:26 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine/engine.h>
#include "engine/sprites/store.h"

static void	__draw_sprite(t_engine_sprite *sprite, t_vec2 pos)
{
	if (!sprite || !sprite->asset)
		return ;
	engine()->gfx->draw_image(sprite->asset, pos);
}

static void	__draw_sprite_rect(t_engine_sprite *sprite, t_vec2 pos, t_gfx_rect rect)
{
	if (!sprite || !sprite->asset)
		return ;
	engine()->gfx->draw_image_rect(sprite->asset, pos, rect);
}

t_engine_sprites_store_renderer	*__engine_sprites_get_renderer(void)
{
	static t_engine_sprites_store_renderer	renderer;

	renderer.draw = __draw_sprite;
	renderer.draw_rect = __draw_sprite_rect;
	return (&renderer);
}
