/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:54:29 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 17:38:15 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/objects/player.h"
#include <engine/engine.h>
#include <oop/oop.h>

t_player	*player(void)
{
	oop()->push(engine()->gameplay_player);
	return ((t_player *)this());
}

t_player	*ply(void)
{
	return (player());
}

t_player	*pthis(void)
{
	return (player());
}

static t_camera_component	*__get_camera(void)
{
	return (this()->get_component(COMPONENT_CAMERA));
}

static t_physics_component	*__get_physics(void)
{
	return (this()->get_component(COMPONENT_PHYSICS));
}

t_player	*new_player(t_new_player def)
{
	t_player	*player;

	if (engine()->get_object_by_tag("player"))
		return (NULL);
	def.ent.obj.size = sizeof(t_player);
	player = (t_player *)new_object(def.ent.obj);
	if (!player)
		return (NULL);
	if (!player->add_component(\
		COMPONENT_CAMERA, \
		new_camera_component(PLAYER_FOV, true, player->get_transform()), \
		false \
	))
		return (oop()->pop(player), free(player), NULL);
	if (!player->add_component(\
		COMPONENT_PHYSICS, \
		new_physics_component(10.0f), \
		false \
	))
		return (oop()->pop(player), free(player), NULL);
	player->get_camera = __get_camera;
	player->get_physics = __get_physics;
	return (player);
}
