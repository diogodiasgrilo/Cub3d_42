/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:42:39 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/05 14:30:58 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

void	free_split(char **strs);
char	**check_map(int fd, t_lay *lay);
void	find_player(t_game *g, char **map);
void	find_path(char **map, int x, int y, int *c);
char	**check_params(int argc, char **argv, t_lay *lay);

#endif