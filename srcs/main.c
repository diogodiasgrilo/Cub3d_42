/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:26:30 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/04 11:38:42 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

int	main(int argc, char *argv[])
{
	char	**map;
	t_lay	lay;

	map = check_params(argc, argv, &lay);
	start_game(map, lay);
	return (0);
}
