/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsed.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:42:39 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 18:10:18 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSED_H
# define PARSED_H

# include "raycasting.h"
# include "game.h"

typedef struct s_map_errors
{
	int		current_fd;
	int		inv_north;
	int		inv_south;
	int		inv_west;
	int		inv_east;
	int		inv_floor;
	int		inv_ceiling;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceiling_color;
	char	*line_of_map;
}				t_map_errors;

t_map_errors	*init_parser(void);
int				count_rows(char **map);
void			free_split(char **strs);
t_map_errors	*map_parser(char *file);
char			**check_map(int fd, t_lay *lay);
char			**check_params(char **argv, t_lay *lay);
void			inset_color(int *add_color, int *dest, char*origin);
void			inset_file(int *add_direc, char **dest, char*origin);

#endif
