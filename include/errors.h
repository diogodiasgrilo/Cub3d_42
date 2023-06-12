/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:18:53 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/09 20:08:54 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "raycasting.h"

typedef struct s_err
{
	int	inv_rowlen;
	int	inv_char;
	int	inv_n_players;
	int	inv_borders;
}				t_err;

t_err	ft_newmap_error(void);
int		error_msg_params(char *msg, char **map_str);
int		ft_print_map_error(t_err *map_err, char **map_str);

#endif