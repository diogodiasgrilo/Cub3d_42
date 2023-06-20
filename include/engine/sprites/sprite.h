/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:06:20 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 16:23:25 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include <std.h>
# include <gfx/image.h>

typedef struct s_sprite
{
	char		*path;
	t_vec2		size;
	double		ratio;
	t_gfx_image	*asset;
}				t_engine_sprite;

t_engine_sprite	*engine_sprites_load_sprite_from_disk(char *path);
void			engine_sprites_free_sprite(t_engine_sprite *sprite);

#endif
