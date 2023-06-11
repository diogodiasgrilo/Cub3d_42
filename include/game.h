/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:03:46 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/09 21:52:14 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "raycasting.h"


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

/* Main attributes for the game */
typedef struct s_game
{
	int				width;
	int				height;
	int				px;
	int				py;
	float			pdx;
	float			pdy;
	float			pa;
	void			*id;
	void			*w_id;
	t_image_creator	map_buffer;
	t_image_creator	scene;
	void			*player;
	t_lay			*lay;
	t_lay			lay_bak;
	char			direction;
	int				keys[6];
	char			**map;
	
}				t_game;

int				free_map_exit(void *game);
void			start_game(char **map, t_lay lay);
void			ft_newgame(t_game *g, char **m, t_lay *lay);

#endif