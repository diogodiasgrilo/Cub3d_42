/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:12:01 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 17:48:00 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAYOUT_H
# define LAYOUT_H

# include "errors.h"
# include "raycasting.h"

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 2
# endif

typedef struct s_lay
{
	int			n_row;
	int			n_col;
	int			n_pl;
	int			n_gh;
	int			n_collect;
	int			current_fd;
	char		*map_first_line;
}				t_lay;

t_lay			ft_newlayout(char *map_first_line);
void			ft_readlayout(int fd, t_err *map_err, t_lay *lay,
					char **map_str);
void			empty_map(char *line, char *last_line, char **map_str);
int				ft_checklayout(char *line, t_err *map_err, t_lay *lay);
void			invalid_char(t_err *map_err, char **map_str, char *orig_line);
char			*cleanup_and_prepare_for_next(t_err *map_err, char **map_str, \
					char *line, t_lay *lay);

#endif