/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:12:01 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/04 12:56:37 by diogpere         ###   ########.fr       */
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
	char		**map_cpy_split;
	char		*map_cpy;
	int			n_row;
	int			n_col;
	int			n_exit;
	int			n_pl;
	int			n_gh;
	int			n_collect;
}				t_lay;

t_lay			ft_newlayout(void);
void			ft_readlayout(int fd, t_err *map_err, t_lay *lay,
					char **map_str);
int				ft_checklayout(char *line, t_err *map_err, t_lay *lay, \
				int is_last);

#endif