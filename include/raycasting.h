/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:34:24 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/11 11:03:07 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cross_compatibility.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "layout.h"
# include "game.h"
# include "check.h"
# include "errors.h"
# include "colors.h"
# include <mlx.h>
# include <libft.h>

# define PI					3.1415926535
# define HALF_PI			PI / 2
# define DR					0.0174533
# define WIDTH				750
# define HEIGHT				WIDTH
# define FOV				PI / 3
# define HALF_FOV			FOV / 2
# define NUM_RAYS			floor(WIDTH / 2)
# define HALF_NUM_RAYS		floor(NUM_RAYS / 2)
# define DELTA_ANGLE		FOV / NUM_RAYS
# define HALF_WIDTH			floor(WIDTH / 2)
# define HALF_HEIGHT		floor(HEIGHT / 2)
# define SCREEN_DIST		HALF_WIDTH / tan(HALF_FOV)
# define SCALE				floor(WIDTH / NUM_RAYS)
# define WALL_HEIGHT		30
# define MINIMAP_RATIO		30
# define MAP_SIZE			10
# define RAY_ANGLE			FOV / NUM_RAYS
# define N_RAYS_PER_ANGLE	NUM_RAYS / FOV
# define SIZE				10

# define PLAYER_CAMERA_SPEED	0.01

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

typedef struct s_put_on_screen
{
	int		color;
	float	y;
	float	starting_x;
	float	starting_y;
	float	distance;
	float	proj_height;
	float	half_width;
	float	half_height;
	float	screen_dis;
	int		scale;
}				t_put_on_screen;

void		draw_rays(t_game *g);
void		*create_player(void *mlx);
int			ft_input(int key, void *param);
int			ft_release(int key, void *param);
void		handle_angles(t_game *g, int key);
t_mlx_image	create_image(void *mlx, t_lay lay, char **map);
void		draw_map(t_mlx_image *ic, t_lay *lay, char **map);
void		create_rows(t_mlx_image *ic, t_lay lay, char **map);
void		my_mlx_pixel_put(t_mlx_image *data, float x, float y, int color);
void		mlx_clear_image (t_mlx_image *data, int color, int width, int height);
void		draw_line(t_game *g, float pdx, float pdy, float ray_angle, int ray);
void		put_on_screen(t_game *g, t_line_drawing *rs, int *column_n, float ray_angle);
int			on_new_frame(void);

#endif
