/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_camera.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:45:44 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 16:40:48 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_CAMERA_H
# define C_CAMERA_H

# include <std.h>
# include <engine/transform.h>

typedef struct s_camera_component	t_camera_component;
typedef t_camera_component			t_camera;

struct s_camera_component
{
	double		fov;
	bool		primary;
	t_transform	*transform;
};

t_camera_component	*new_camera_component(double fov, bool primary, t_transform *transform);

#endif
