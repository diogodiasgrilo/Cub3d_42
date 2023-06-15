/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:42:56 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 14:43:23 by martiper         ###   ########.fr       */
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
	engine()->gfx->draw_circle((t_gfx_circle){
		.center = vec2i(400, 300),
		.radius = 20,
		.color = 0xFFFFFFFF
	});
	engine()->gfx->draw_line((t_gfx_line){
		.start = vec2i(400, 300),
		.direction = vec2f(0.0, -1.0),
		.color = 0xFFFF0000,
		.length = 45.0
	});
	engine()->gfx->render();
	engine()->start();
	return (0);
}
