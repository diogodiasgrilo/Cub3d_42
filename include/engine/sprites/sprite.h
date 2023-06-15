/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:06:20 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 13:09:34 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include <std.h>
# include <engine/gfx.h>

typedef struct s_sprite
{
	char		*path;
	t_vec2		dimensions;
	t_gfx_image	*image;
}				t_sprite;

/*
		* Loads a sprite from a file.
		* Returns a pointer to the sprite.
 */
t_sprite		*new_sprite(char *path);
void			free_sprite(t_sprite *sprite);

#endif
