/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:42:56 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 18:05:31 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <std.h>
#include <engine/engine.h>
#include <utils/log.h>


int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (!engine()->init(WINDOW_TITLE, (t_vec2){WINDOW_WIDTH, WINDOW_HEIGHT}))
		(logger())->error("Failed to initialize the engine!");
	engine()->gameplay_player = new_player((t_new_player){
		.ent = {
			.obj = {
				.empty_transform = true,
				.tag = "player"
			}
		}
	});
	engine()->add_object((t_object *)engine()->gameplay_player);

	t_object *demo = new_object((t_new_object){
		.position = vec3(1, 1, 0),
		.rotation = 0,
		.tag = "demo",
		.size = 0
	});

	demo->add_component(COMPONENT_MATERIAL, \
		new_material_component(engine()->materials->get("demo", true)), \
		false \
	);

	engine()->add_object(demo);

	mlx_do_key_autorepeatoff(engine()->gfx->mlx);
	engine()->start();
	return (0);
}
