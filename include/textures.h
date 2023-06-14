/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:22:53 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/14 16:33:36 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "raycasting.h"
# include "game.h"

# define TEXTURE_SIZE 256
# define HALF_TEXTURE_SIZE floor(TEXTURE_SIZE / 2)
# define PLAYER_SIZE_SCALE 60

typedef	struct	s_texture
{
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}				t_texture;


typedef struct	s_textures
{
	float		offset;
	void		*texture;
    void		*texture_hor;
	void		*texture_vert;
	t_texture	*port;
    t_texture	*vwall;
	t_texture	*piping;
	t_texture	*gate;
	t_texture	*sky;
	t_texture	*portal_gun;
}				t_textures;

#endif