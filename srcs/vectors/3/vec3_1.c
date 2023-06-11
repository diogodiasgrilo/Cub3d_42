/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:33:50 by martiper          #+#    #+#             */
/*   Updated: 2023/06/11 10:55:19 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec3	vec3_scale(t_vec3 a, double scale)
{
	return (vec3_mul_scal(a, scale));
}

t_vec3	vec3_invert(t_vec3 a)
{
	return ((t_vec3){-a.x, -a.y, -a.z});
}

t_vec3	vec3_normalize(t_vec3 a)
{
	t_vec3	vec;
	double	magnitude;

	magnitude = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	vec.x = a.x / magnitude;
	vec.y = a.y / magnitude;
	vec.z = a.z / magnitude;
	return (vec);
}

t_vec3	vec3_clamp(t_vec3 a, t_vec3 min, t_vec3 max)
{
	t_vec3	vec;

	vec = a;
	if (vec.x < min.x)
		vec.x = min.x;
	else if (vec.x > max.x)
		vec.x = max.x;
	if (vec.y < min.y)
		vec.y = min.y;
	else if (vec.y > max.y)
		vec.y = max.y;
	if (vec.z < min.z)
		vec.z = min.z;
	else if (vec.z > max.z)
		vec.z = max.z;
	return (vec);
}

double	vec3_length(t_vec3 a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}
