/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_camera.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:45:44 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 15:33:08 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_CAMERA_H
# define C_CAMERA_H

# include <std.h>

typedef struct s_camera_component	t_camera_component;

struct s_camera_component
{
	double	fov;
	bool	primary;
};

t_camera_component	*new_camera_component(double fov, bool primary);

#endif
