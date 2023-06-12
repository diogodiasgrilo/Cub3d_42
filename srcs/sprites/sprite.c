/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:41:41 by martiper          #+#    #+#             */
/*   Updated: 2023/06/10 19:14:14 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites/sprite.h"
#include <utils/log.h>

void	free_sprite(t_sprite *sprite)
{
	t_game	*game;

	game = get_game();
	if (!game)
		return ;
	if (!sprite)
	{
		ft_printf(LOG_ERROR"Attempted to free NULL sprite, how?\n");
		return ;
	}
	ft_printf(
		LOG_INFO
		"Cleaning up sprite at path: %s\n",
		sprite->path);
	if (sprite->image && sprite->image->img)
		mlx_destroy_image(game->id, sprite->image->img);
	if (sprite->image)
		free(sprite->image);
	if (sprite->path)
		free(sprite->path);
	free(sprite);
}

static t_sprite	*define_sprite(t_game *game, char *path)
{
	t_sprite	*sprite;

	sprite = ft_calloc(1, sizeof(t_sprite));
	if (!sprite)
		return (NULL);
	sprite->path = ft_strdup(path);
	sprite->image = ft_calloc(1, sizeof(t_mlx_image));
	if (!sprite->image)
	{
		free_sprite(sprite);
		return (NULL);
	}
	sprite->image->img = mlx_xpm_file_to_image(game->id, path,
			(int *)&sprite->dimensions.x, (int *)&sprite->dimensions.y);
	sprite->image->width = sprite->dimensions.x;
	sprite->image->height = sprite->dimensions.y;
	if (!sprite->image->img)
	{
		free_sprite(sprite);
		return (NULL);
	}
	sprite->image->data = mlx_get_data_addr(\
		sprite->image->img, &sprite->image->bpp,
			&sprite->image->size_line, &sprite->image->endian);
	return (sprite);
}

// TODO: Add a scaling macro
/* if (sprite->dimensions.x != SPRITE_SIZE
	|| sprite->dimensions.y != SPRITE_SIZE)
{
	sprite->dimensions = vec2(SPRITE_SIZE, SPRITE_SIZE);
	gfx_resize_image(window->mlx, &sprite->image, sprite->dimensions);
} */
t_sprite	*new_sprite(char *path)
{
	t_sprite				*sprite;

	sprite = define_sprite(get_game(), path);
	return (sprite);
}
