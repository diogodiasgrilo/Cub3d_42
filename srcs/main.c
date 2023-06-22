/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:26:30 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/22 11:10:20 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	clean_texture(void *mlx, t_texture *tex)
{
	mlx_destroy_image(mlx, tex->img);
	free(tex);
}

void	clean_textures(t_game *g)
{
	if (g->textures)
	{
		clean_texture(g->id, g->textures->north);
		clean_texture(g->id, g->textures->south);
		clean_texture(g->id, g->textures->east);
		clean_texture(g->id, g->textures->west);
		clean_texture(g->id, g->textures->sky);
		clean_texture(g->id, g->textures->portal_gun);
	}
}

void	free_map_file(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
	close(fd);
}

void	destroy_all_mlx_images(void)
{
	t_game	*g;

	g = get_game();
	clean_textures(g);
	if (g->map_buffer.img)
		mlx_destroy_image(g->id, g->map_buffer.img);
	if (g->scene.img)
		mlx_destroy_image(g->id, g->scene.img);
	if (g->player)
		mlx_destroy_image(g->id, g->player);
	if (g->map)
		ft_split_free(g->map);
	if (g->parsed)
		free_parsed(g->parsed);
	if (!g->id)
		return ;
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
	if (!parsed)
		return (0);
	get_game()->parsed = parsed;
	check_parsed(parsed);
	lay.map_first_line = ft_strdup(parsed->line_of_map);
	lay.current_fd = parsed->current_fd;
	map = check_params(argv, &lay);
	start_game(map, lay, parsed);
	destroy_all_mlx_images();
	return (0);
}
