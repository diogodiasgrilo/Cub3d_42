/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_methods.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:43:45 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 18:44:42 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_METHODS_H
# define WINDOW_METHODS_H

# include "window.h"
# include "draw.h"

void	__window_clear(bool draw);
void	__window_render(void);
bool	__window_setup(t_vec2 size, char *title);
void	__window_start(void);
void	__window_hook_new_frame(int (*f)(void));

void	__window_draw_pixel(t_vec2 pos, u_int32_t color);
void	__window_draw_line(t_gfx_line line);
void	__window_draw_rect(t_gfx_rect rect);
void	__window_draw_circle(t_gfx_circle circle);
void	__window_draw_image(t_gfx_image *image, t_vec2 pos);
void	__window_draw_image_rect(\
	t_gfx_image *image, t_vec2 pos, t_gfx_rect rect);

#endif
