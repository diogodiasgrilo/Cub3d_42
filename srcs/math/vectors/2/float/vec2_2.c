/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:46:42 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 13:04:13 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math/vec.h"

t_vec2f	vec2f_div(t_vec2f a, t_vec2f b)
{
	t_vec2f	vec;

	vec.x = a.x / b.x;
	vec.y = a.y / b.y;
	return (vec);
}

t_vec2f	vec2f_div_scal(t_vec2f a, double constant)
{
	t_vec2f	vec;

	vec.x = a.x / constant;
	vec.y = a.y / constant;
	return (vec);
}

double	vec2f_dist(t_vec2f a, t_vec2f b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}
