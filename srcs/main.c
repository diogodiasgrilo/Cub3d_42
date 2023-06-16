/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:42:56 by martiper          #+#    #+#             */
/*   Updated: 2023/06/16 15:12:25 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <std.h>
#include <engine/engine.h>
#include <utils/log.h>


int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (!engine()->init("Cub3D", (t_vec2){800, 600}))
		(logger())->error("Failed to initialize the engine!");
	engine()->start();
	return (0);
}
