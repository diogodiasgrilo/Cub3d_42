/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:06:20 by martiper          #+#    #+#             */
/*   Updated: 2023/06/10 18:59:27 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include <vec2.h>
# include <game.h>

typedef struct s_sprite
{
	char		*path;
	t_vec2		dimensions;
	t_mlx_image	*image;
}				t_sprite;

/*
		* Loads a sprite from a file.
		* Returns a pointer to the sprite.
 */
t_sprite		*new_sprite(char *path);
void			free_sprite(t_sprite *sprite);

#endif
