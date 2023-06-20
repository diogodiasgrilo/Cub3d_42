/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:53:15 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 17:43:13 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/object.h"
#include <oop/oop.h>

bool	__components_add_component(t_comp_labels label, void *data, bool frozen);
bool	__components_remove_component(t_comp_labels label);
bool	__components_has_component(t_comp_labels label);
void	*__components_get_component(t_comp_labels label);
bool	__components_is_component_frozen(t_comp_labels label);

void	__object_update(double delta_time);
void	__object_render(double delta_time);

t_identity_component	*__object_get_identity(void);
t_transform				*__object_get_transform(void);
t_vec3f					*__object_get_position(void);
double					*__object_get_rotation(void);
void					__object_set_position(t_vec3f position);
void					__object_set_rotation(double rotation);

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
	this()->id = &identity->id;
	this()->tag = identity->tag;
	this()->transform = transform;
	this()->get_identity = __object_get_identity;
	this()->get_transform = __object_get_transform;
	this()->get_position = __object_get_position;
	this()->get_rotation = __object_get_rotation;
	this()->set_position = __object_set_position;
	this()->set_rotation = __object_set_rotation;
	return (true);
}

t_object	*new_object(t_new_object def)
{
	t_object	*object;

	if (def.size == 0)
		def.size = sizeof(t_object);
	object = ft_calloc(1, def.size);
	if (!object)
		return (NULL);
	object->__components = NULL;
	object->add_component = __components_add_component;
	object->remove_component = __components_remove_component;
	object->get_component = __components_get_component;
	object->has_component = __components_has_component;
	object->is_component_frozen = __components_is_component_frozen;
	object->update = __object_update;
	object->render = __object_render;
	oop()->push(object);
	if (!__setup_initial_components(def))
		return (oop()->pop(object), free(object), NULL);
	return (object);
}
