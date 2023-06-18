/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:20:48 by martiper          #+#    #+#             */
/*   Updated: 2023/06/18 23:31:50 by martiper         ###   ########.fr       */
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

typedef struct s_engine	t_engine;

typedef bool			(*t_engine_init)(char *title, t_vec2 size);

struct s_engine
{
	t_gfx_window			*gfx;
	t_engine_sprites_store	*assets;
	t_engine_input			*input;
	t_engine_parser			*parser;
	t_engine_materials		*materials;

	t_engine_init			init;
	void					(*start)(void);
	void					(*update)(double delta);
};

t_engine	*engine(void);

#endif
