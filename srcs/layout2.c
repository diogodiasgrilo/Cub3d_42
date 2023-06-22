/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:46:35 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/22 11:10:20 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

t_lay	ft_newlayout(char *map_first_line)
{
	t_lay	lay;

	lay.n_row = 0;
	lay.n_col = 0;
	lay.n_pl = 0;
	lay.n_collect = 0;
	lay.map_first_line = map_first_line;
	return (lay);
}

void	invalid_char(t_err *map_err, char **map_str, char *orig_line)
{
	free(*map_str);
	map_err->inv_char = 1;
	ft_print_map_error(map_err, &orig_line);
}

void	empty_map(char *line, char *last_line, char **map_str)
{
	if (line)
		free(line);
	if (last_line)
		free(last_line);
	if (*map_str)
		free(*map_str);
	error_msg_params("Map is empty!", NULL);
}

char	*cleanup_and_prepare_for_next(t_err *map_err, char **map_str, \
	char *line, t_lay *lay)
{
	char	*last_line;

	if (ft_checklayout(line, map_err, lay))
		invalid_char(map_err, map_str, line);
	last_line = ft_strdup(line);
	line = ft_strjoin_free(line, "\n");
	*map_str = ft_strjoin_free(*map_str, line);
	lay->n_row++;
	free(line);
	return (last_line);
}
