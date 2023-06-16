/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:08:03 by martiper          #+#    #+#             */
/*   Updated: 2023/06/16 14:50:45 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "image.h"
# include <math/vec.h>
# include "gfx/draw.h"

typedef bool	(*t_gfx_window_setup)(t_vec2 size, char *title);
typedef void	(*t_gfx_window_draw_pixel)(t_vec2 pos, u_int32_t color);
typedef void	(*t_gfx_window_draw_image)(t_gfx_image *image, t_vec2 pos);
typedef void	(*t_gfx_window_draw_image_rect)(\
	t_gfx_image *image, t_vec2 pos, t_gfx_rect rect);

typedef struct s_gfx_window
{
	void							*mlx;
	void							*win;
	t_gfx_image						*render_buffer;
	t_vec2							size;
	bool							started;
	bool							focused;

	void							(*clear)(bool draw);
	void							(*render)(void);
	t_gfx_window_setup				setup;
	void							(*start)(void);
	void							(*hook_new_frame)(int (*f)(void));

	t_gfx_window_draw_pixel			draw_pixel;
	void							(*draw_line)(t_gfx_line line);
	void							(*draw_rect)(t_gfx_rect rect);
	void							(*draw_circle)(t_gfx_circle circle);
	t_gfx_window_draw_image			draw_image;
	t_gfx_window_draw_image_rect	draw_image_rect;

	t_gfx_image						*(*new_image)(int width, int height);
	t_gfx_image						*(*new_image_from_path)(char *path);
	void							(*destroy_image)(t_gfx_image *image);
}	t_gfx_window;

t_gfx_window	*get_window(void);

#endif
