/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:33:50 by martiper          #+#    #+#             */
/*   Updated: 2023/06/11 10:55:19 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec2f	vec2f_scale(t_vec2f a, double scale)
{
	t_vec2f	vec;

	vec.x = a.x * scale;
	vec.y = a.y * scale;
	return (vec);
}

t_vec2f	vec2f_invert(t_vec2f a)
{
	t_vec2f	vec;

	vec.x = -a.x;
	vec.y = -a.y;
	return (vec);
}

t_vec2f	vec2f_normalize(t_vec2f a)
{
	t_vec2f	vec;
	double	magnitude;

	magnitude = sqrt(a.x * a.x + a.y * a.y);
	vec.x = a.x / magnitude;
	vec.y = a.y / magnitude;
	return (vec);
}

t_vec2f	vec2f_clamp(t_vec2f a, t_vec2f min, t_vec2f max)
{
	t_vec2f	vec;

	vec.x = a.x;
	vec.y = a.y;
	if (vec.x < min.x)
		vec.x = min.x;
	else if (vec.x > max.x)
		vec.x = max.x;
	if (vec.y < min.y)
		vec.y = min.y;
	else if (vec.y > max.y)
		vec.y = max.y;
	return (vec);
}

double	vec2f_length(t_vec2f a)
{
	return (sqrt(a.x * a.x + a.y * a.y));
}
