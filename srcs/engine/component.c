/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:50:55 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 14:17:13 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <std.h>
#include <oop/oop.h>
#include <engine/object.h>
#include "engine/component.h"

// TODO: FIND A WAY TO CASCADE A DESTRUCTOR TO A COMPONENT

bool	__components_add_component(t_comp_labels label, void *data, bool frozen)
{
	static u_int64_t	__id;
	t_component			*component;
	t_list				*node;

	if (this()->has_component(label))
		return (false);
	component = ft_calloc(1, sizeof(t_component));
	if (!component)
		return (false);
	component->__id = __id++;
	component->__tag = label;
	component->__data = data;
	component->__frozen = frozen;
	node = ft_lstnew(component);
	if (!node)
		return (free(component), false);
	ft_lstadd_back(&this()->__components, node);
	return (true);
}

bool	__components_remove_component(t_comp_labels label)
{
	t_list		*node;
	t_component	*component;

	node = this()->__components;
	while (node)
	{
		component = node->content;
		if (component->__tag == label && !component->__frozen)
		{
			ft_lstremove(&this()->__components, node, free);
			return (true);
		}
		node = node->next;
	}
	return (false);
}

bool	__components_has_component(t_comp_labels label)
{
	t_list	*node;

	node = this()->__components;
	while (node)
	{
		if (((t_component *)node->content)->__tag == label)
			return (true);
		node = node->next;
	}
	return (false);
}

void	*__components_get_component(t_comp_labels label)
{
	t_list	*node;

	node = this()->__components;
	while (node)
	{
		if (((t_component *)node->content)->__tag == label)
			return (((t_component *)node->content)->__data);
		node = node->next;
	}
	return (NULL);
}

bool	__components_is_component_frozen(t_comp_labels label)
{
	t_component	*component;

	component = __components_get_component(label);
	if (component)
		return (component->__frozen);
	return (false);
}
