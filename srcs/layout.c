/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:28:07 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/22 12:26:45 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	check_for_map_first_line(t_lay *lay, char **line, int fd)
{
	if (lay->map_first_line)
	{
		*line = lay->map_first_line;
		lay->map_first_line = NULL;
	}
	else
		*line = get_next_line(fd);
}

void	check_special_lines(\
	char *line, \
	char **map_str, \
	char *last_line, \
	int fd \
)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && (ft_strlen(line) > 1 || (*line != '\n' && *line != '\0')))
		{
			free(line);
			free(last_line);
			error_msg_params("Invalid Map!", map_str);
		}
	}
}

void	ft_readlayout(int fd, t_err *map_err, t_lay *lay, char **map_str)
{
	char	*line;
	char	*last_line;

	line = NULL;
	last_line = NULL;
	while (1)
	{
		check_for_map_first_line(lay, &line, fd);
		if (!line || !*line || *line == '\n')
		{
			if (!lay->n_col)
				empty_map(line, last_line, map_str);
			else
			{
				ft_checklayout(last_line, map_err, lay);
				check_special_lines(line, map_str, last_line, fd);
			}
			free(last_line);
			break ;
		}
		free(last_line);
		last_line = cleanup_and_prepare_for_next(map_err, map_str, line, lay);
	}
	free(lay->map_first_line);
	free_map_file(fd);
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
