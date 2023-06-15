/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:11:25 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 17:57:37 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORE_H
# define STORE_H

# include "sprite.h"
# include <gfx/draw.h>

typedef struct s_sprites_store			t_engine_sprites_store;
typedef struct s_sprites_store_renderer	t_engine_sprites_store_renderer;

struct s_sprites_store_renderer
{
	void	(*draw)(t_engine_sprite *sprite, t_vec2 pos);
	void	(*draw_rect)(t_engine_sprite *sprite, t_vec2 pos, t_gfx_rect rect);
};

struct s_sprites_store
{
	t_list							*list;
	t_engine_sprites_store_renderer	*renderer;
	t_engine_sprite					*(*get)(char *path);
};

t_engine_sprites_store	*engine_sprites_get_store(void);

#endif
