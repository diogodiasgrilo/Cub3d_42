/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:42:56 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 18:37:54 by martiper         ###   ########.fr       */
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
	t_gfx_image	*sprite = engine()->gfx->new_image_from_path("assets/textures/tester.xpm");
	if (!sprite)
		(logger())->error("Failed to load the sprite!");
	else
		logger()->debug("Loaded sprite with size %d,%d", sprite->width, sprite->height);
	engine()->start();
	return (0);
}
