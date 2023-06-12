/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:03:46 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 12:01:14 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "raycasting.h"
# include "textures.h"
# include "parsed.h"

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
	t_image_creator	demo_tex;
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
	t_map_errors	*parsed;
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

int				free_map_exit(void *game);
void			free_parsed(t_map_errors *parsed);
void			check_parsed(t_map_errors *parsed);
void			find_player(t_game *g, char **map);
void			ft_newgame(t_game *g, char **m, t_lay *lay);
void			load_textures(t_game *g, t_map_errors *parsed);
void			start_game(char **map, t_lay lay, t_map_errors *parsed);

#endif
