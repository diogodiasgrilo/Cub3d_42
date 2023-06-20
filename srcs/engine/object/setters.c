/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:25:17 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 15:25:43 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine/object.h>

void	__object_set_position(t_vec3f position)
{
	this()->get_transform()->position = position;
}
void	__object_set_rotation(double rotation)
{
	this()->get_transform()->rotation = rotation;
}
