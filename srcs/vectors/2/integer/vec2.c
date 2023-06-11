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

t_vec2	vec2i(int x, int y)
{
	t_vec2	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

t_vec2	vec2i_add(t_vec2 a, t_vec2 b)
{
	t_vec2	vec;

	vec.x = a.x + b.x;
	vec.y = a.y + b.y;
	return (vec);
}

t_vec2	vec2i_sub(t_vec2 a, t_vec2 b)
{
	t_vec2	vec;

	vec.x = a.x - b.x;
	vec.y = a.y - b.y;
	return (vec);
}

t_vec2	vec2i_mul(t_vec2 a, t_vec2 b)
{
	t_vec2	vec;

	vec.x = a.x * b.x;
	vec.y = a.y * b.y;
	return (vec);
}

t_vec2	vec2i_mul_scal(t_vec2 a, int constant)
{
	t_vec2	vec;

	vec.x = a.x * constant;
	vec.y = a.y * constant;
	return (vec);
}
