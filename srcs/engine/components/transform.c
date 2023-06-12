/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:11:48 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 20:52:41 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <std.h>
#include "engine/components/c_transform.h"

t_transform_component	*new_transform_component(\
	t_vec3f position, \
	double rotation \
)
{
	t_transform_component	*transform;

	transform = ft_calloc(1, sizeof(t_transform_component));
	if (!transform)
		return (NULL);
	transform->position = position;
	transform->rotation = rotation;
	return (transform);
}
