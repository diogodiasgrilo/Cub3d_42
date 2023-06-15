/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:09:49 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 14:10:02 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <std.h>
#include <gfx/window.h>
#include "gfx/image.h"

u_int32_t	gfx_get_pixel_from_image(t_gfx_image *image, t_vec2 pos)
{
	char	*addr;

	if (!image || !image->data)
		return (0);
	if (
		pos.x < 0 || pos.y >= image->width || \
		pos.y < 0 || pos.y >= image->height
	)
		return (0);
	addr = image->data + (pos.y * image->size_line + pos.x * (image->bpp / 8));
	return (*(u_int32_t *)addr);
}

static void	resize_image(\
	t_gfx_image *image, \
	t_gfx_image *new_image, \
	t_vec2 new_size \
)
{
	t_vec2	iter;

	iter = vec2i(0, 0);
	while (iter.y < new_size.y)
	{
		iter.x = 0;
		while (iter.x < new_size.x)
		{
			gfx_put_pixel_in_image(new_image, iter,
				gfx_get_pixel_from_image(image, vec2i(\
					(int)(iter.x * image->width / new_size.x), \
					(int)(iter.y * image->height / new_size.y)) \
				),
				true);
			iter.x++;
		}
		iter.y++;
	}
}

void	gfx_resize_image(t_gfx_image *image, t_vec2 new_size)
{
	t_gfx_image	*new_image;

	if (!image || !image->img)
		return ;
	new_image = gfx_new_image(new_size.x, new_size.y);
	if (!new_image)
		return ;
	resize_image(image, new_image, new_size);
	mlx_destroy_image(get_window()->mlx, image->img);
	*image = *new_image;
	free(new_image);
}
