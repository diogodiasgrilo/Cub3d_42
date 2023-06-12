/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:39:08 by martiper          #+#    #+#             */
/*   Updated: 2023/06/11 12:12:05 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H

# include <vectors.h>
# include <game.h>

typedef struct s_gfx_line
{
	t_vec2f			start;
	t_vec2f			direction;
	double			length;
	unsigned int	color;
	int				thickness;
	t_mlx_image		*buffer;
}	t_gfx_line;

void	gfx_draw_line(t_gfx_line line);

#endif
