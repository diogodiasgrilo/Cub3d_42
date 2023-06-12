/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:14:35 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 23:39:38 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gfx/window.h>
#include <utils/log.h>

void	sl_free_sprite(t_sl_sprite *sprite)
{
	t_sl_window	*window;

	window = get_window_ctx();
	if (!window)
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
		mlx_destroy_image(window->mlx, sprite->image->img);
	if (sprite->image)
		free(sprite->image);
	if (sprite->path)
		free(sprite->path);
	free(sprite);
}

static	t_sl_sprite	*define_sprite(t_sl_window *window, char *path)
{
	t_sl_sprite	*sprite;

	sprite = ft_calloc(1, sizeof(t_sl_sprite));
	if (!sprite)
		return (NULL);
	sprite->path = ft_strdup(path);
	sprite->image = ft_calloc(1, sizeof(t_mlx_image));
	if (!sprite->image)
	{
		sl_free_sprite(sprite);
		return (NULL);
	}
	sprite->image->img = mlx_xpm_file_to_image(window->mlx, path,
			(int *)&sprite->dimensions.x, (int *)&sprite->dimensions.y);
	sprite->image->width = sprite->dimensions.x;
	sprite->image->height = sprite->dimensions.y;
	if (!sprite->image->img)
	{
		sl_free_sprite(sprite);
		return (NULL);
	}
	sprite->image->addr = mlx_get_data_addr(\
		sprite->image->img, &sprite->image->bits_per_pixel,
			&sprite->image->line_length, &sprite->image->endian);
	return (sprite);
}

static void	add_sprite_to_store(t_list **store, t_sl_sprite *sprite)
{
	t_list					*node;

	if ((*store) && (*store)->content == NULL)
		(*store)->content = sprite;
	else
	{
		node = ft_lstnew(sprite);
		if (!node)
		{
			sl_free_sprite(sprite);
			return ;
		}
		ft_lstadd_back(store, node);
	}
}

t_sl_sprite	*sl_load_sprite(char *path)
{
	t_sl_sprite				*sprite;
	t_sl_window				*window;
	t_sl_sprite_store		*store;

	window = get_window_ctx();
	store = get_sprite_store_ctx();
	if (!window || !path || !store)
		return (NULL);
	sprite = sl_get_sprite(path);
	if (sprite)
		return (sprite);
	sprite = define_sprite(window, path);
	if (!sprite)
		return (NULL);
	if (sprite->dimensions.x != SPRITE_SIZE
		|| sprite->dimensions.y != SPRITE_SIZE)
	{
		sprite->dimensions = vec2(SPRITE_SIZE, SPRITE_SIZE);
		gfx_resize_image(window->mlx, &sprite->image, sprite->dimensions);
	}
	add_sprite_to_store(&store, sprite);
	return (sprite);
}
