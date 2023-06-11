/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:33:50 by martiper          #+#    #+#             */
/*   Updated: 2023/06/11 10:55:19 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec2f	vec2f(double x, double y)
{
	t_vec2f	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

t_vec2f	vec2f_add(t_vec2f a, t_vec2f b)
{
	t_vec2f	vec;

	vec.x = a.x + b.x;
	vec.y = a.y + b.y;
	return (vec);
}

t_vec2f	vec2f_sub(t_vec2f a, t_vec2f b)
{
	t_vec2f	vec;

	vec.x = a.x - b.x;
	vec.y = a.y - b.y;
	return (vec);
}

t_vec2f	vec2f_mul(t_vec2f a, t_vec2f b)
{
	t_vec2f	vec;

	vec.x = a.x * b.x;
	vec.y = a.y * b.y;
	return (vec);
}

t_vec2f	vec2f_mul_scal(t_vec2f a, double constant)
{
	t_vec2f	vec;

	vec.x = a.x * constant;
	vec.y = a.y * constant;
	return (vec);
}
