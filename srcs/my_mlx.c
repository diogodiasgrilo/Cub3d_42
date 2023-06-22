/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:17:36 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/22 11:10:20 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	my_mlx_pixel_put(t_image_creator *data, float x, float y, int color)
{
	int	x_i;
	int	y_i;

	x_i = x;
	y_i = y;
	if (x_i >= 0 && x_i < settings()->width && \
		y_i >= 0 && y_i < settings()->height)
		(*(unsigned int*)(data->data + ((y_i * data->size_line) \
		+ (x_i * (data->bpp / 8))))) = color;
}

void	mlx_clear_image(t_image_creator *data, int color, \
	int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	mlx_draw_image_to_image(t_image_creator *buff, \
	t_image_creator *img, int x, int y)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			color = (*(unsigned int *)(img->data + \
				((i * img->size_line) + (j * (img->bpp / 8)))));
			my_mlx_pixel_put(buff, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
