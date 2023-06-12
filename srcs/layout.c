/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:28:07 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 12:05:26 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

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

void	ft_readlayout(int fd, t_err *map_err, t_lay *lay, char **map_str)
{
	char		*line;
	char		*last_line;

	line = NULL;
	last_line = NULL;
	while (1)
	{
		if (lay->map_first_line)
		{
			line = lay->map_first_line;
			lay->map_first_line = NULL;
		}
		else
			line = get_next_line(fd);
		if (!line)
		{
			if (!lay->n_col)
				empty_map(line, last_line, map_str);
			else
				ft_checklayout(last_line, map_err, lay);
			free(last_line);
			break ;
		}
		free(last_line);
		// change_spaces_to_ones(&line);
		if (ft_checklayout(line, map_err, lay))
			invalid_char(map_err, map_str, line);
		last_line = ft_strdup(line);
		line = ft_strjoin_free(line, "\n");
		*map_str = ft_strjoin_free(*map_str, line);
		lay->n_row++;
		free(line);
	}
	free(lay->map_first_line);
	close(fd);
}

int	ft_checklayout(char *line, t_err *map_err, t_lay *lay)
{
	if (!lay->n_col)
	lay->n_col = ft_strlen(line);
	lay->n_pl += ft_countchar(line, 'N');
	lay->n_pl += ft_countchar(line, 'S');
	lay->n_pl += ft_countchar(line, 'E');
	lay->n_pl += ft_countchar(line, 'W');
	lay->n_gh += ft_countchar(line, 'G');
	map_err->inv_n_players = (lay->n_pl < 1 || lay->n_pl > 1);
	while (line && *line)
		if (!ft_strchr("01NSEW \n", *(line++)))
			return (1);
	return (0);
}
