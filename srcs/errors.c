/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:41:56 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/20 16:11:42 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void	free_parsed(t_map_errors *parsed)
{
	if (parsed->north_texture != NULL)
		free(parsed->north_texture);
	if (parsed->south_texture != NULL)
		free(parsed->south_texture);
	if (parsed->west_texture != NULL)
		free(parsed->west_texture);
	if (parsed->east_texture != NULL)
		free(parsed->east_texture);
	free(parsed);
}

void	check_parsed(t_map_errors *parsed)
{
	if (parsed->inv_north != 0)
		ft_printf("Error\ninvalid north texture!\n");
	else if (parsed->inv_south != 0)
		ft_printf("Error\ninvalid south texture!\n");
	else if (parsed->inv_west != 0)
		ft_printf("Error\ninvalid west texture!\n");
	else if (parsed->inv_east != 0)
		ft_printf("Error\ninvalid east texture!\n");
	else if (parsed->inv_floor != 0)
		ft_printf("Error\ninvalid floor color!\n");
	else if (parsed->inv_ceiling != 0)
		ft_printf("Error\ninvalid ceiling color!\n");
	else
		return ;
	free_parsed(parsed);
	exit(EXIT_FAILURE);
}

int	error_msg_params(char *msg, char **map_str)
{
	if (map_str && *map_str)
		free(*map_str);
	ft_printf("Error\n%s\n", msg);
	exit(0);
	return (0);
}

int	ft_print_map_error(t_err *map_err, char **map_str)
{
	if (map_err->inv_char)
		error_msg_params("Unexpected char(s) in map!", map_str);
	if (map_err->inv_rowlen)
		error_msg_params("Map must be rectangular!", map_str);
	if (map_err->inv_borders)
		error_msg_params("Map must be surrounded by walls!", map_str);
	if (map_err->inv_n_players)
		error_msg_params("Invalid number of players!", map_str);
	return (0);
}
