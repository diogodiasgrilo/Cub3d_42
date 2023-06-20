/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:23:25 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 15:38:11 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine/object.h>

t_identity_component	*__object_get_identity(void)
{
	return (this()->get_component(COMPONENT_IDENTITY));
}
t_transform	*__object_get_transform(void)
{
	return (this()->get_component(COMPONENT_TRANSFORM));
}
t_vec3f	*__object_get_position(void)
{
	return (&this()->get_transform()->position);
}
double	*__object_get_rotation(void)
{
	return (&this()->get_transform()->rotation);
}
