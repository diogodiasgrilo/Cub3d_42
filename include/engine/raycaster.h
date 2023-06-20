/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:05:47 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 16:30:00 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include <std.h>
# include <gfx/window.h>

# define HALF_WIDTH (WINDOW_WIDTH / 2)
# define HALF_HEIGHT (WINDOW_HEIGHT / 2)
# define FOV (M_PI / 3)
# define HALF_FOV (FOV / 2)
# define NUM_RAYS HALF_WIDTH
# define HALF_NUM_RAYS (NUM_RAYS / 2)
# define DELTA_ANGLE (FOV / NUM_RAYS)
# define MAX_DEPTH 100
# define SCALE (WINDOW_WIDTH / NUM_RAYS)

# define SCREEN_DIST (HALF_WIDTH / tan(HALF_FOV))

typedef struct s_projection	t_projection;

struct s_projection
{
	t_vec2			screen;
	double			dist;
	double			norm_dist;
	double			coefficent;
	t_vec2			size;

	t_engine_sprite	*sprite;
	int				sprite_half_width;
	t_vec2			sprite_pos;
};

#endif
