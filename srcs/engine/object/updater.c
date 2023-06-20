/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:39:52 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 16:20:51 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine/object.h>

void	__object_update(double delta_time)
{
	t_physics_component		*physics;
	t_material_component	*material;

	physics = this()->get_component(COMPONENT_PHYSICS);
	if (physics)
		physics->update(delta_time);
	material = this()->get_component(COMPONENT_MATERIAL);
	if (material)
		material->update(delta_time);
}
