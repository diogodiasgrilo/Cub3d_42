/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:48:57 by martiper          #+#    #+#             */
/*   Updated: 2023/06/10 18:59:51 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites/store.h"

static void	add_sprite_to_store(t_list **store, t_sprite *sprite)
{
	t_list					*node;

	if ((*store) && (*store)->content == NULL)
		(*store)->content = sprite;
	else
	{
		node = ft_lstnew(sprite);
		if (!node)
		{
			free_sprite(sprite);
			return ;
		}
		ft_lstadd_back(store, node);
	}
}

t_sprite_store	*get_sprite_store(void)
{
	return (get_game()->sprite_store);
}

t_sprite	*get_sprite(char *path)
{
	t_list			*node;
	t_sprite		*sprite;

	node = get_sprite_store();
	if (!node)
		return (NULL);
	while (node)
	{
		sprite = node->content;
		if (ft_strcmp(sprite->path, path) == 0)
			return (sprite);
		node = node->next;
	}
	sprite = new_sprite(path);
	if (!sprite)
		return (NULL);
	add_sprite_to_store(&get_game()->sprite_store, sprite);
	return (sprite);
}
