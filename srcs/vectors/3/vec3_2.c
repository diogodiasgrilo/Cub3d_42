/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:46:42 by martiper          #+#    #+#             */
/*   Updated: 2023/06/11 10:55:19 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec3	vec3_div(t_vec3 a, t_vec3 b)
{
	t_vec3	vec;

	vec.x = a.x / b.x;
	vec.y = a.y / b.y;
	return (vec);
}

t_vec3	vec3_div_scal(t_vec3 a, double constant)
{
	t_vec3	vec;

	vec.x = a.x / constant;
	vec.y = a.y / constant;
	return (vec);
}

double	vec3_dist(t_vec3 a, t_vec3 b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}
