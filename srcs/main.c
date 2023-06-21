/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:26:30 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 18:49:49 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void destroy_all_mlx_images()
{
	t_game *g;

	g = get_game();
	mlx_destroy_image(g->id, g->textures->north->img);
	mlx_destroy_image(g->id, g->textures->south->img);
	mlx_destroy_image(g->id, g->textures->east->img);
	mlx_destroy_image(g->id, g->textures->west->img);
	mlx_destroy_image(g->id, g->textures->sky->img);
	mlx_destroy_image(g->id, g->textures->portal_gun->img);
	mlx_destroy_image(g->id, g->map_buffer.img);
	mlx_destroy_image(g->id, g->scene.img);
	mlx_destroy_image(g->id, g->player);
	ft_split_free(g->map);
	//mlx_destroy_image(g->id, g->textures->;
	mlx_destroy_window(g->id, g->w_id);
	if (OS != 1)
		mlx_destroy_display(g->id);
	free(g->id);
}

int	main(int argc, char *argv[])
{
	char			**map;
	t_lay			lay;
	t_map_errors	*parsed;

	if (argc != 2)
		error_msg_params("Invalid number of arguments!", 0);
	parsed = map_parser(argv[1]);
	check_parsed(parsed);
	lay.map_first_line = parsed->line_of_map;
	lay.current_fd = parsed->current_fd;
	map = check_params(argv, &lay);
	start_game(map, lay, parsed);
	destroy_all_mlx_images();
	return (0);
}
