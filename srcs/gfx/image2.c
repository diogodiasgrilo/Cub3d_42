/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:09:49 by martiper          #+#    #+#             */
/*   Updated: 2023/06/21 11:43:15 by martiper         ###   ########.fr       */
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
		pos.x < 0 || pos.x >= image->width || \
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

t_gfx_image	*gfx_new_image_from_path(char *path)
{
	t_gfx_window	*window;
	t_gfx_image		*image;

	window = get_window();
	if (!window || !window->mlx || !path)
		return (NULL);
	image = ft_calloc(1, sizeof(t_gfx_image));
	if (!image)
		return (NULL);
	image->img = mlx_xpm_file_to_image(window->mlx, path, \
		&image->width, &image->height);
	if (!image->img)
		return (free(image), NULL);
	image->data = mlx_get_data_addr(\
		image->img, &image->bpp, &image->size_line, &image->endian \
	);
	if (!image->data)
		return (mlx_destroy_image(window->mlx, image->img), free(image), NULL);
	return (image);
}
