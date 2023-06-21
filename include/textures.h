/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:22:53 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 18:11:42 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "raycasting.h"
# include "game.h"

typedef struct s_portal_gun
{
	int		gun_width;
	int		gun_height;
	int		x_start;
	int		y_start;
	int		x;
	int		y;
	int		color;
	char	*gun_data;
}				t_portal_gun;

typedef struct s_texture
{
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}				t_texture;

typedef struct s_textures
{
	float		offset;
	void		*texture;
	void		*texture_hor;
	void		*texture_vert;
	t_texture	*north;
	t_texture	*south;
	t_texture	*east;
	t_texture	*west;
	t_texture	*sky;
	t_texture	*portal_gun;
	char		*floor_color;
	char		*ceiling_color;
}				t_textures;

#endif
