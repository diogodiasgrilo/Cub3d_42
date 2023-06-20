/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:20:48 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 16:46:54 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <std.h>
# include <gfx/window.h>
# include <engine/sprites/store.h>
# include <engine/input.h>
# include <engine/parser.h>
# include <engine/materials.h>
# include <engine/objects/player.h>

typedef struct s_engine	t_engine;

typedef bool			(*t_engine_init)(char *title, t_vec2 size);

struct s_engine
{
	t_gfx_window			*gfx;
	t_engine_sprites_store	*assets;
	t_engine_input			*input;
	t_engine_parser			*parser;
	t_engine_materials		*materials;
	double					delta_time;

	t_engine_init			init;
	void					(*start)(void);
	void					(*update)(double delta);
	void					(*render)(double delta);

	t_list					*objects;
	t_object				*(*get_object)(u_int32_t id);
	t_object				*(*get_object_by_tag)(char *tag);
	bool					(*add_object)(t_object *obj);

	t_camera				*gameplay_camera;
	t_player				*gameplay_player;
};

t_engine	*engine(void);

#endif
