/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:09:45 by martiper          #+#    #+#             */
/*   Updated: 2023/06/21 17:17:32 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

t_settings	*settings(void)
{
	static t_settings	var;

	if (!var.pi)
		var = (t_settings){
			.pi = PI, .half_pi = PI / 2,
			.width = WIDTH, .height = HEIGHT,
			.fov = PI / 3, .half_fov = FOV / 2,
			.num_rays = WIDTH,
			.delta_angle = FOV / NUM_RAYS,
			.half_width = floor(WIDTH / 2),
			.half_height = floor(HEIGHT / 2),
			.screen_dist = HALF_WIDTH / tan(HALF_FOV),
			.scale = floor(WIDTH / NUM_RAYS),
			.map_size = MAP_SIZE,
			.player_size = PLAYER_SIZE,
			.half_player_size = PLAYER_SIZE / 2,
			.mouse_sensitivity = 0.01 * WIDTH,
			.player_camera_speed = PLAYER_CAMERA_SPEED,
			.mouse_safe_area_left = (WIDTH * 0.125),
			.mouse_safe_area_right = (WIDTH - MOUSE_SAFE_AREA_LEFT),
		};
	return (&var);
}
