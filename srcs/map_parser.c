/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:44:21 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 18:44:43 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

int	find_type(t_map_errors *errors, char *trim_line, char *check)
{
	if (ft_strncmp(check, "NO", 3) == 0)
		inset_file(&errors->inv_north, &errors->north_texture, trim_line);
	else if (ft_strncmp(check, "SO", 3) == 0)
		inset_file(&errors->inv_south, &errors->south_texture, trim_line);
	else if (ft_strncmp(check, "WE", 3) == 0)
		inset_file(&errors->inv_west, &errors->west_texture, trim_line);
	else if (ft_strncmp(check, "EA", 3) == 0)
		inset_file(&errors->inv_east, &errors->east_texture, trim_line);
	else if (ft_strncmp(check, "F", 2) == 0)
		inset_color(&errors->inv_floor, &errors->floor_color, trim_line);
	else if (ft_strncmp(check, "C", 2) == 0)
		inset_color(&errors->inv_ceiling, &errors->ceiling_color, trim_line);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	insert_value(t_map_errors *errors, char *line, char *check, int i)
{
	int		test;
	int		color_or_texture;
	char	*trim_line;

	color_or_texture = 0;
	while (line[i + color_or_texture] && line[i + color_or_texture] != 32)
		color_or_texture++;
	if (ft_strncmp(line + i, check, color_or_texture) != 0)
		return (EXIT_SUCCESS);
	i += color_or_texture;
	while (line[i] && line[i] == 32)
		i++;
	trim_line = ft_strtrim((line + i), "\n");
	test = open(trim_line, O_RDONLY);
	if (test < 0 && color_or_texture > 1)
		return (EXIT_FAILURE);
	else if (test > -1)
		close(test);
	if (find_type(errors, trim_line, check))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	line_check(char **line, t_map_errors *errors)
{
	int	i;

	if (*line)
		free(*line);
	*line = get_next_line(errors->current_fd);
	if (!*line)
		return (EXIT_FAILURE);
	i = 0;
	while ((*line)[i] && ((*line)[i] == 32 || (*line)[i] == '\t'))
		i++;
	if ((*line)[i] == '\n' || (*line)[i] == '\0' ||
		(ft_strncmp(*line + i, "NO ", 3) == 0 && \
		insert_value(errors, *line, "NO", i) != EXIT_FAILURE) ||
		(ft_strncmp(*line + i, "SO ", 3) == 0 && \
		insert_value(errors, *line, "SO", i) != EXIT_FAILURE) ||
		(ft_strncmp(*line + i, "WE ", 3) == 0 && \
		insert_value(errors, *line, "WE", i) != EXIT_FAILURE) ||
		(ft_strncmp(*line + i, "EA ", 3) == 0 && \
		insert_value(errors, *line, "EA", i) != EXIT_FAILURE) ||
		(ft_strncmp(*line + i, "F ", 2) == 0 && \
		insert_value(errors, *line, "F", i) != EXIT_FAILURE) ||
		(ft_strncmp(*line + i, "C ", 2) == 0 && \
		insert_value(errors, *line, "C", i) != EXIT_FAILURE))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

t_map_errors	*map_parser(char *file)
{
	char			*line;
	t_map_errors	*errors;

	line = NULL;
	errors = init_parser();
	errors->current_fd = open(file, O_RDONLY);
	if (errors->current_fd < 0)
		return (NULL);
	while (1)
		if (line_check(&line, errors) == EXIT_FAILURE)
			break ;
	errors->line_of_map = line;
	return (errors);
}
