/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:53:15 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 14:27:05 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/object.h"
#include <oop/oop.h>

bool	__components_add_component(t_comp_labels label, void *data, bool frozen);
bool	__components_remove_component(t_comp_labels label);
bool	__components_has_component(t_comp_labels label);
void	*__components_get_component(t_comp_labels label);
bool	__components_is_component_frozen(t_comp_labels label);

t_object	*object(void)
{
	return (oop()->get());
}

t_object	*obj(void)
{
	return (oop()->get());
}

t_object	*this(void)
{
	return (oop()->get());
}

static bool	__setup_initial_components(t_new_object def)
{
	t_transform_component	*transform;
	t_identity_component	*identity;
	char					default_tag[512];

	if (def.empty_transform)
	{
		def.position = vec3(0, 0, 0);
		def.rotation = 0;
	}
	transform = new_transform_component(def.position, def.rotation);
	if (!transform)
		return (false);
	if (!this()->add_component(COMPONENT_TRANSFORM, transform, true))
		return (false);
	identity = new_identity_component(NULL);
	if (!identity)
		return (false);
	if (!def.tag)
	{
		ft_sprintf(default_tag, 512, "object_%d", identity->id);
		def.tag = default_tag;
	}
	identity->tag = ft_strdup(def.tag);
	if (!this()->add_component(COMPONENT_IDENTITY, identity, true))
		return (false);
	return (true);
}

t_object	*new_object(t_new_object def)
{
	t_object	*object;

	object = ft_calloc(1, def.size);
	if (!object)
		return (NULL);
	object->__components = NULL;
	object->add_component = __components_add_component;
	object->remove_component = __components_remove_component;
	object->get_component = __components_get_component;
	object->has_component = __components_has_component;
	object->is_component_frozen = __components_is_component_frozen;
	oop()->push(object);
	if (!__setup_initial_components(def))
	{
		oop()->pop();
		free(object);
		return (NULL);
	}
	return (object);
}
