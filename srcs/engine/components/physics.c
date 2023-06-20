/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:26:20 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 18:03:35 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <std.h>
#include "engine/components/c_physics.h"
#include <engine/object.h>
#include <engine/component.h>

static void	__update(double delta_time)
{
	t_physics_component		*physics;
	t_transform_component	*transform;

	physics = this()->get_component(COMPONENT_PHYSICS);
	transform = this()->get_transform();
	if (!physics || !transform)
		return ;
	transform->position.x += physics->velocity.x * cos(transform->rotation);
	transform->position.y += physics->velocity.y * sin(transform->rotation);
	transform->position.z += physics->velocity.z;
	physics->velocity.x += physics->acceleration.x;
	physics->velocity.y += physics->acceleration.y;
	physics->velocity.z += physics->acceleration.z;

	physics->acceleration.x = 0;
	physics->acceleration.y = 0;
	physics->acceleration.z = 0;

	// make velocity decay quadratically when no acceleration is applied
	physics->velocity.x *= 0.666;
	physics->velocity.y *= 0.666;
	physics->velocity.z *= 0.666;

	if (transform->position.z > 0)
		physics->acceleration.z = -9.81 * physics->mass * delta_time;
	else
	{
		transform->position.z = 0;
		physics->velocity.z = 0;
		physics->acceleration.z = 0;
	}
}

static void	__apply_force(t_vec3f direction, double force)
{
	t_physics_component	*physics;

	physics = this()->get_component(COMPONENT_PHYSICS);
	if (!physics)
		return ;
	physics->acceleration.x += direction.x * force / physics->mass;
	physics->acceleration.y += direction.y * force / physics->mass;
	physics->acceleration.z += direction.z * force / physics->mass;
}

static void	__halt(void)
{
	t_physics_component	*physics;

	physics = this()->get_component(COMPONENT_PHYSICS);
	if (!physics)
		return ;
	physics->acceleration.x = 0;
	physics->acceleration.y = 0;
	physics->acceleration.z = 0;
	physics->velocity.x = 0;
	physics->velocity.y = 0;
	physics->velocity.z = 0;
}

t_physics_component	*new_physics_component(double mass)
{
	t_physics_component	*physics;

	physics = ft_calloc(1, sizeof(t_physics_component));
	if (!physics)
		return (NULL);
	physics->mass = mass;
	physics->update = __update;
	physics->apply_force = __apply_force;
	physics->halt = __halt;
	return (physics);
}
