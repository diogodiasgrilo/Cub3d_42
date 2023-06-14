/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:03:46 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/14 16:23:51 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "raycasting.h"
# include "textures.h"

typedef struct s_image_creator
{
	int		x;
	int		y;
	char	*data;
	void	*img;
	int		pix_index;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}				t_image_creator;

typedef struct s_game
{
	float		sin_a;
	float		cos_a;
	double		y_hor;
	double		x_hor;
	double		y_vert;
	double		x_vert;
	float		dx;
	float		dy;
	float		depth_hor;
	float		depth_vert;
	float		delta_depth;
	float		depth;
	float		ray_angle;
	int			x_map;
	int			y_map;
	double		width;
	double		height;
	double		px;
	double		py;
	float		pdx;
	float		pdy;
	float		pa;
	void		*id;
	void		*w_id;
	t_image_creator	map_buffer;
	t_image_creator	scene;
	void		*player;
	void		*sky;
	t_lay		*lay;
	t_lay		lay_bak;
	char		**map;
	float		prev_height;
	int			direction;
	int			keys[6];
	t_textures	*textures;
	double		sky_offset_x;
}				t_game;

typedef struct s_handle_directions
{
	float	npx;
	float	npy;
	float	ndx;
	float	ndy;
	float	fx;
	float	fy;
	float	rx;
	float	ry;
}				t_handle_directions;

void			load_textures(t_game *g);
int				free_map_exit(void *game);
void			start_game(char **map, t_lay lay);
void			ft_newgame(t_game *g, char **m, t_lay *lay);

#endif