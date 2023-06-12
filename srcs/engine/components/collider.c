/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:42:46 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 20:23:51 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine/object.h>
#include <engine/component.h>
#include "engine/components/c_collider.h"

static bool	__collides(t_object *other)
{
	t_collision_compute	c_this;
	t_collision_compute	c_other;

	c_this.collider = this()->get_component(COMPONENT_COLLIDER);
	c_other.collider = other->get_component(COMPONENT_COLLIDER);
	if (!c_this.collider || !c_other.collider)
		return (false);
	c_this.transform = this()->get_transform();
	c_other.transform = other->get_transform();
	if (!c_this.transform || !c_other.transform)
		return (false);
	return (
		c_this.transform->position.x - c_this.collider->size.x / 2
		< c_other.transform->position.x + c_other.collider->size.x / 2
		&& c_this.transform->position.x + c_this.collider->size.x / 2
		> c_other.transform->position.x - c_other.collider->size.x / 2
		&& c_this.transform->position.y - c_this.collider->size.y / 2
		< c_other.transform->position.y + c_other.collider->size.y / 2
		&& c_this.transform->position.y + c_this.collider->size.y / 2
		> c_other.transform->position.y - c_other.collider->size.y / 2
		&& c_this.transform->position.z - c_this.collider->size.z / 2
		< c_other.transform->position.z + c_other.collider->size.z / 2
		&& c_this.transform->position.z + c_this.collider->size.z / 2
		> c_other.transform->position.z - c_other.collider->size.z / 2
	);
}

static void	__update(void)
{
}

static void	__draw(void)
{
}

t_collider_component	*new_collider_component(\
	t_collider_type type, \
	t_vec3f scale \
)
{
	t_collider_component	*collider;

	collider = ft_calloc(1, sizeof(t_collider_component));
	if (!collider)
		return (NULL);
	collider->type = type;
	collider->size = scale;
	collider->collides = __collides;
	collider->update = __update;
	collider->draw = __draw;
	return (collider);
}
