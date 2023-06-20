/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:30:40 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 17:53:42 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine/engine.h>
#include <engine/object.h>
#include "engine/components/c_material.h"
#include <utils/log.h>

static void	__material_set(char *name)
{
	t_engine_material		*mat;
	t_material_component	*component;

	mat = engine()->materials->get(name, true);
	if (mat)
	{
		component = this()->get_component(COMPONENT_MATERIAL);
		component->mat = mat;
		component->sprite = mat->sprites[0];
	}
	else
		(logger())->error("Material %s not found", name);
}

static void	__material_update(double delta_time)
{
	(void)delta_time;
}

t_material_component	*new_material_component(t_engine_material *mat)
{
	t_material_component	*component;

	if (!mat)
		return (NULL);
	component = ft_calloc(1, sizeof(t_material_component));
	component->mat = mat;
	component->sprite = mat->sprites[0];
	component->set = __material_set;
	component->update = __material_update;
	return (component);
}
