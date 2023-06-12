/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:26:20 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 20:41:29 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <std.h>
#include "engine/components/c_physics.h"
#include <engine/object.h>
#include <engine/component.h>

typedef struct s_physics_component	t_physics_component;

struct s_physics_component
{
	double	mass;
	t_vec3f	velocity;
	t_vec3f	acceleration;
	void	(*update)(void);
	void	(*apply_force)(t_vec3f direction, double force);
	void	(*halt)(void);
};

static void	__update(void)
{
	t_physics_component		*physics;
	t_transform_component	*transform;

	physics = this()->get_component(COMPONENT_PHYSICS);
	transform = this()->get_transform();
	if (!physics || !transform)
		return ;
	transform->position.x += physics->velocity.x;
	transform->position.y += physics->velocity.y;
	transform->position.z += physics->velocity.z;
	physics->velocity.x += physics->acceleration.x;
	physics->velocity.y += physics->acceleration.y;
	physics->velocity.z += physics->acceleration.z;
	physics->acceleration = vec3_sub(\
		physics->acceleration, \
		vec3_mul_scal(physics->acceleration, 0.1));
	if (transform->position.z <= 0)
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
