/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:26:30 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 18:36:25 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

int	main(int argc, char *argv[])
{
	char			**map;
	t_lay			lay;
	t_map_errors	*parsed;

	if (argc != 2)
		error_msg_params("Invalid number of arguments!", 0);
	parsed = map_parser(argv[1]);
	if (!parsed)
		return (0);
	check_parsed(parsed);
	lay.map_first_line = parsed->line_of_map;
	lay.current_fd = parsed->current_fd;
	map = check_params(argv, &lay);
	start_game(map, lay, parsed);
	return (0);
}
