/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:27:27 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 17:55:09 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine/object.h>
#include <engine/engine.h>
#include <engine/raycaster.h>
#include <std.h>

void	__object_render(void)
{
	t_camera				*cam;
	t_vec3f					*pos;
	double					theta;
	t_vec3f					delta;
	double					delta_angle;
	double					delta_rays;
	t_projection			proj;
	t_material_component	*mat;

	cam = engine()->gameplay_camera;
	pos = this()->get_position();
	mat = this()->get_component(COMPONENT_MATERIAL);
	if (!cam || !pos || !mat || !mat->sprite)
		return ;
	delta = vec3_sub(*pos, cam->transform->position);
	theta = atan2(delta.y, delta.x);

	delta_angle = theta - cam->transform->rotation;
	if ((delta.x > 0 && cam->transform->rotation > PI) || (delta.x < 0 && delta.y < 0))
		delta_angle += TAU;
	delta_rays = delta_angle / DELTA_ANGLE;
	proj.screen.x = (HALF_NUM_RAYS + delta_rays) * SCALE;
	proj.dist = hypot(delta.x, delta.y);
	proj.norm_dist = proj.dist * cos(delta_angle);
	if (\
		-(mat->sprite->size.x / 2) < proj.screen.x && \
		proj.screen.x < (WINDOW_WIDTH + mat->sprite->size.x / 2) && \
		proj.norm_dist > 0.5
	)
	{
		proj.coefficent = SCREEN_DIST / proj.norm_dist;
		proj.size = vec2i(proj.coefficent * mat->sprite->ratio, proj.coefficent);

		proj.sprite = mat->sprite;
		proj.sprite_half_width = proj.sprite->size.x / 2;
		proj.sprite_pos = vec2i(proj.screen.x - proj.sprite_half_width, HALF_HEIGHT - proj.size.y / 2);
		engine()->gfx->draw_image_rect(proj.sprite->asset, proj.sprite_pos, (t_gfx_rect){
			.size = proj.size,
			.start = vec2i(0, 0)
		});
	}
}
