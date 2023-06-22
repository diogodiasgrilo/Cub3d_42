/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_objects2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:02:11 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/22 11:10:20 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	determine_color(t_put_on_screen	*sc)
{
	t_determine_color	dc;

	dc.max_distance = 0.0f;
	dc.min_distance = 200.0f;
	dc.height = 0.0f;
	sc->color = 0xFFFFFF;
	if (sc->proj_height > dc.min_distance)
		dc.height = dc.min_distance;
	else if (sc->proj_height < dc.max_distance)
		dc.height = dc.max_distance;
	else
		dc.height = sc->proj_height;
	dc.ratio = (dc.height - dc.min_distance) / (dc.max_distance - \
		dc.min_distance);
	dc.white = 0xFFFFFF;
	dc.grey = 0x808080;
	dc.red = (int)(((dc.white >> 16) & 0xFF) * (1.0f - dc.ratio) + \
		((dc.grey >> 16) & 0xFF) * dc.ratio);
	dc.green = (int)(((dc.white >> 8) & 0xFF) * (1.0f - dc.ratio) + \
		((dc.grey >> 8) & 0xFF) * dc.ratio);
	dc.blue = (int)((dc.white & 0xFF) * (1.0f - dc.ratio) + \
		(dc.grey & 0xFF) * dc.ratio);
	sc->color = (dc.red << 16) | (dc.green << 8) | dc.blue;
}
