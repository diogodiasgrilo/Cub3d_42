/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:57:10 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 13:31:50 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <math/vec.h>

typedef struct s_gfx_image
{
	char	*data;
	void	*img;
	int		pix_index;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_gfx_image;

t_gfx_image	*gfx_new_image(int width, int height);
void		gfx_put_pixel_in_image(\
	t_gfx_image *image, \
	t_vec2 pos, \
	u_int32_t color, \
	bool	draw_black \
);
void		gfx_draw_image(t_gfx_image *image, t_vec2 position);
void		gfx_clear_image(t_gfx_image *image);
void		gfx_destroy_image(t_gfx_image *image);
u_int32_t	gfx_get_pixel_from_image(t_gfx_image *image, t_vec2 pos);
void		gfx_resize_image(t_gfx_image *image, t_vec2 size);

#endif
