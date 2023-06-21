/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_par_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:41:39 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/21 11:54:15 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

int		check_top_bottom_row(char **map, int *y, int x)
{
	x = 0;
	
	while (map[*y][x] && map[*y][x] == 32)
		x++;
	while (map[*y][x] && (map[*y][x] == '1' || map[*y][x] == 32))
		x++;
	if (map[*y][x])
		return (EXIT_FAILURE);
	*y = 1;
	return (EXIT_SUCCESS);
}

int		check_walls(char **map)
{
	int	y;
	int	x;
	int num_row;
	
	y = 0;
	x = 0;
	if (check_top_bottom_row(map, &y, x))
		return (EXIT_FAILURE);
	num_row = count_rows(map);
	while (y < num_row - 1)
	{
		x = -1;
		while (map[y][++x])
		{
			// printf("x = %d, strlen y - 1: %d strleny + 1: %d / we are at :%c\n", x, ft_strlen(map[y - 1]), ft_strlen(map[y + 1]), map[y][x]);
			if (((x >= ft_strlen(map[y + 1]) || x >= ft_strlen(map[y - 1])) && map[y][x] != '1') || ( \
				map[y][x] != '1' && (map[y - 1][x] == 32 || map[y + 1][x] == 32 || (x == 0 && map[y][x] != '1') || \
				(!map[y][x + 1] && map[y][x + 1] != '1'))))
				return (EXIT_FAILURE);
		}
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
	map = ft_split(map_str, '\n');
	if (check_walls(map))
		map_err.inv_borders = 1;
	ft_print_map_error(&map_err, &map_str);
	free(map_str);
	if (!map)
		error_msg_params("Error\nMemory allocation error!", 0);
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
