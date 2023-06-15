/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:20:48 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 18:32:39 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <std.h>
# include <gfx/window.h>
# include "sprites/store.h"

typedef struct s_engine	t_engine;

typedef bool			(*t_engine_init)(char *title, t_vec2 size);

struct s_engine
{
	t_gfx_window			*gfx;
	t_engine_sprites_store	*assets;

	t_engine_init			init;
	void					(*start)(void);
	void					(*update)(double delta);
};

t_engine	*engine(void);

#endif
