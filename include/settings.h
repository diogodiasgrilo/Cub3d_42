/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:08:24 by martiper          #+#    #+#             */
/*   Updated: 2023/06/21 17:19:34 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

typedef struct s_settings
{
	double	pi;
	double	half_pi;
	int		width;
	int		height;
	double	fov;
	double	half_fov;
	int		num_rays;
	double	delta_angle;
	double	half_width;
	double	half_height;
	double	screen_dist;
	int		scale;
	int		map_size;
	int		player_size;
	int		half_player_size;
	double	mouse_sensitivity;
	double	player_camera_speed;
	int		mouse_safe_area_left;
	int		mouse_safe_area_right;
}	t_settings;

t_settings	*settings(void);

#endif
