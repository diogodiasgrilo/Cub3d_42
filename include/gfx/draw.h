/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:14:50 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 18:07:22 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "image.h"
# include <math/vec.h>

typedef struct s_gfx_line	t_gfx_line;
typedef struct s_gfx_rect	t_gfx_rect;
typedef struct s_gfx_circle	t_gfx_circle;

struct s_gfx_line
{
	t_vec2		start;
	t_vec2f		direction;
	double		length;
	u_int32_t	color;
};

struct s_gfx_rect
{
	t_vec2		start;
	t_vec2		size;
	u_int32_t	color;
	bool		fill;
};

struct s_gfx_circle
{
	t_vec2		center;
	double		radius;
	u_int32_t	color;
};

void	gfx_draw_pixel(t_gfx_image *image, t_vec2 pos, u_int32_t color);
void	gfx_draw_line(t_gfx_image *image, t_gfx_line line);
void	gfx_draw_rect(t_gfx_image *image, t_gfx_rect rect);
void	gfx_draw_circle(t_gfx_image *image, t_gfx_circle circle);
void	gfx_draw_image_rect(t_gfx_image *render, t_gfx_image *image, t_vec2 pos, t_gfx_rect rect);

#endif
