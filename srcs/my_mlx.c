/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:17:36 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 17:16:13 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void	my_mlx_pixel_put(t_image_creator *data, float x, float y, int color)
{
	int	x_i, y_i;

	x_i = x;
	y_i = y;

	if (x_i >= 0 && x_i < settings()->width && y_i >= 0 && y_i < settings()->height)
		(*(unsigned int*)(data->data + ((y_i * data->size_line) + (x_i * (data->bpp / 8))))) = color;

}

void	mlx_clear_image (t_image_creator *data, int color, int width, int height)
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
