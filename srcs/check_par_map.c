/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_par_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:41:39 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/22 11:10:20 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	check_top_bottom_row(char **map, int *y, int x)
{
	x = 0;
	while (map[*y][x] && map[*y][x] == 32)
		x++;
	if (!map[*y][x])
		return (EXIT_FAILURE);
	while (map[*y][x] && (map[*y][x] == '1' || map[*y][x] == 32))
		x++;
	if (map[*y][x])
		return (EXIT_FAILURE);
	*y = 1;
	return (EXIT_SUCCESS);
}

int	check_open_walls(char **map, int y, int x)
{
	if (((x >= (int)ft_strlen(map[y + 1]) || x >= \
	(int)ft_strlen(map[y - 1])) \
	&& map[y][x] != '1' && map[y][x] == '0') || \
	(map[y][x] != '1' && map[y][x] == '0' && \
	(map[y - 1][x] == 32 || map[y + 1][x] == 32 || \
	(x == 0 && map[y][x] != '1') || (!map[y][x + 1] && \
	map[y][x + 1] != '1' && map[y][x] == '0'))))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_walls(char **map, t_lay *lay)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (check_top_bottom_row(map, &y, x))
		return (EXIT_FAILURE);
	while (y < lay->n_row - 1)
	{
		x = -1;
		while (map[y][++x])
			if (check_open_walls(map, y, x))
				return (EXIT_FAILURE);
		y++;
	}
	if (check_top_bottom_row(map, &y, x))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

char	**check_map(int fd, t_lay *lay)
{
	char	**map;
	char	*map_str;
	t_err	map_err;

	map = 0;
	map_str = 0;
	map_err = ft_newmap_error();
	*lay = ft_newlayout(lay->map_first_line);
	ft_readlayout(fd, &map_err, lay, &map_str);
	map = ft_split(map_str, "\n");
	if (!map)
		error_msg_params("Error\nMemory allocation error!", 0);
	if (check_walls(map, lay))
		map_err.inv_borders = 1;
	get_game()->map = map;
	ft_print_map_error(&map_err, &map_str);
	free(map_str);
	return (map);
}

char	**check_params(char **argv, t_lay *lay)
{
	int	i;
	int	fd;

	i = 0;
	fd = lay->current_fd;
	if (fd < 0)
		error_msg_params("File not found!", 0);
	while (argv[1][i] && argv[1][i] == '.')
		i++;
	while (argv[1][i] && argv[1][i] != '.')
		i++;
	if (ft_strncmp(argv[1] + i, ".cub", 4) || ft_strncmp(argv[1] + i, ".cub",
			ft_strlen(argv[1] + i)))
		error_msg_params("Invalid file type, use .cub!", 0);
	return (check_map(fd, lay));
}
