/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:00:28 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 14:10:06 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <std.h>
#include <gfx/window.h>
#include "gfx/image.h"

t_gfx_image	*gfx_new_image(int width, int height)
{
	t_gfx_window	*window;
	t_gfx_image		*image;

	window = get_window();
	if (!window || !window->mlx)
		return (NULL);
	image = ft_calloc(1, sizeof(t_gfx_image));
	if (!image)
		return (NULL);
	image->img = mlx_new_image(window->mlx, width, height);
	if (!image->img)
		return (free(image), NULL);
	image->data = mlx_get_data_addr(\
		image->img, &image->bpp, &image->size_line, &image->endian \
	);
	if (!image->data)
		return (mlx_destroy_image(window->mlx, image->img), free(image), NULL);
	image->width = width;
	image->height = height;
	return (image);
}

void	gfx_put_pixel_in_image(\
	t_gfx_image *image, \
	t_vec2 pos, \
	u_int32_t color, \
	bool	draw_black \
)
{
	char	*addr;

	if (!image || !image->data)
		return ;
	if (!draw_black && color == 0xFF000000)
		return ;
	if (
		pos.x < 0 || pos.y >= image->width || \
		pos.y < 0 || pos.y >= image->height
	)
		return ;
	addr = image->data + (pos.y * image->size_line + pos.x * (image->bpp / 8));
	*(u_int32_t *)addr = color;
}

void	gfx_draw_image(t_gfx_image *image, t_vec2 position)
{
	t_gfx_window	*window;

	window = get_window();
	if (!window || !window->render_buffer || !image || !image->img)
		return ;
	mlx_put_image_to_window(\
		window->mlx, window->win, \
		image->img, position.x, position.y \
	);
}

void	gfx_clear_image(t_gfx_image *image)
{
	t_gfx_window	*window;

	window = get_window();
	if (!window || !window->render_buffer || !image || !image->img)
		return ;
	ft_bzero(image->data, image->width * image->height * (image->bpp / 8));
}

void	gfx_destroy_image(t_gfx_image *image)
{
	t_gfx_window	*window;

	window = get_window();
	if (!window || !window->mlx || !image || !image->img)
		return ;
	mlx_destroy_image(window->mlx, image->img);
	free(image);
}
