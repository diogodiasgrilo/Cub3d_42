/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:34:09 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 15:35:29 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <std.h>
#include "engine/components/c_camera.h"

t_camera_component	*new_camera_component(double fov, bool primary)
{
	t_camera_component	*camera;

	camera = ft_calloc(1, sizeof(t_camera_component));
	if (!camera)
		return (NULL);
	camera->fov = fov;
	camera->primary = primary;
	return (camera);
}
