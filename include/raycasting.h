/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:34:24 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 12:29:09 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "layout.h"
# include "game.h"
# include "parsed.h"
# include "errors.h"
# include "colors.h"
# include "textures.h"
# include <mlx.h>
# include <libft.h>

# define PI					3.1415926535
# define HALF_PI			PI / 2
# define DR					0.0174533
# define WIDTH				1000
# define HEIGHT				WIDTH
# define FOV				PI / 3
# define HALF_FOV			FOV / 2
# define NUM_RAYS			(WIDTH)
# define HALF_NUM_RAYS		floor(NUM_RAYS / 2)
# define DELTA_ANGLE		FOV / NUM_RAYS
# define HALF_WIDTH			floor(WIDTH / 2)
# define HALF_HEIGHT		floor(HEIGHT / 2)
# define SCREEN_DIST		HALF_WIDTH / tan(HALF_FOV)
# define SCALE				floor(WIDTH / NUM_RAYS)
# define WALL_HEIGHT		30
# define MAP_SIZE			7
# define MAX_DEPTH			100
# define PLAYER_SIZE		4
# define HALF_PLAYER_SIZE	PLAYER_SIZE / 2

# define PLAYER_SPEED		0.1
# define MOUSE_SENSITIVITY	0.01 * WIDTH
# define PLAYER_CAMERA_SPEED	0.05

# define MOUSE_SAFE_AREA_LEFT (WIDTH * 0.125)
# define MOUSE_SAFE_AREA_RIGHT (WIDTH - MOUSE_SAFE_AREA_LEFT)

typedef struct s_line_drawing
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
}				t_line_drawing;

typedef struct s_gfx_line
{
	int				start_x;
	int				start_y;
	float			direction_x;
	float			direction_y;
	double			length;
	unsigned int	color;
	t_image_creator	*buffer;
}	t_gfx_line;

typedef struct t_gfx_point
{
	int				x;
	int				y;
	unsigned int	color;
	t_image_creator	*buffer;
}	t_gfx_point;

typedef struct t_gfx_rect
{
	int				start_x;
	int				start_y;
	int				width;
	int				height;
	unsigned int	color;
	t_image_creator	*buffer;
}	t_gfx_rect;

typedef struct s_put_on_screen
{
	int		y;
	int		end_y;
	int		color;
	int		texture_x;
	int		texture_y;
	float	starting_x;
	float	starting_y;
	float	distance;
	float	proj_height;
}				t_put_on_screen;

void			put_sky(t_game *g);
void			draw_rays(t_game *g);
void			put_portal_gun(t_game *g);
void			*create_player(void *mlx);
void			draw_line(t_gfx_line line);
int				ft_input(int key, void *param);
int				ft_input(int key, void *param);
int				find_biggest_column(char **map);
int				ft_release(int key, void *param);
void			handle_angles(t_game *g, int key);
void    		determine_color (t_put_on_screen *sc);
void			create_rows(t_image_creator *ic, char **map);
t_image_creator	create_image(void *mlx, t_lay lay, char **map);
void			draw_map(t_image_creator *ic, t_lay *lay, char **map);
void			*create_floor_sky(t_game *g, t_put_on_screen proj, int i);
void			put_pixel(t_image_creator *image, int x, int y, int color);
void			my_mlx_pixel_put(t_image_creator *data, float x, float y, int color);
void			mlx_clear_image (t_image_creator *data, int color, int width, int height);
int	on_new_frame(void);
t_game	*get_game(void);

#endif
