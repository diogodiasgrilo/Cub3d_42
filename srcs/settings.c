/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:09:45 by martiper          #+#    #+#             */
/*   Updated: 2023/06/21 18:12:04 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

t_settings	*settings(void)
{
	static t_settings	var;

	if (!var.pi)
	{
		var = (t_settings){
			.pi = PI, .half_pi = PI / 2,
			.width = WIDTH, .height = HEIGHT,
			.fov = PI / 3,
			.num_rays = WIDTH,
			.half_width = floor(WIDTH / 2),
			.half_height = floor(HEIGHT / 2),
			.scale = floor(WIDTH / NUM_RAYS),
			.map_size = MAP_SIZE,
			.player_size = PLAYER_SIZE,
			.half_player_size = PLAYER_SIZE / 2,
			.mouse_sensitivity = 0.01 * WIDTH,
			.player_camera_speed = PLAYER_CAMERA_SPEED,
			.mouse_safe_area_left = (WIDTH * 0.125),
		};
		var.half_fov = var.fov / 2;
		var.delta_angle = var.fov / var.num_rays;
		var.screen_dist = var.half_width / tan(var.half_fov);
		var.mouse_safe_area_right = var.width - var.mouse_safe_area_left;
	}
	return (&var);
}
