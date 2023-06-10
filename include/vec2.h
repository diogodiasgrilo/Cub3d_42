/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:31:21 by martiper          #+#    #+#             */
/*   Updated: 2023/06/10 18:38:00 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_H
# define VEC2_H

# include <math.h>

typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2;

typedef t_vector2	t_vec2;

typedef struct s_vector2f
{
	double	x;
	double	y;
}	t_vector2f;

typedef t_vector2f	t_vec2f;

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}	t_vector3;

typedef t_vector3	t_vec3;
typedef t_vector3	t_vec3f;

t_vec2				vec2i(int x, int y);
t_vec2				vec2i_add(t_vec2 a, t_vec2 b);
t_vec2				vec2i_sub(t_vec2 a, t_vec2 b);
t_vec2				vec2i_mul(t_vec2 a, t_vec2 b);
t_vec2				vec2i_mul_scal(t_vec2 a, int constant);
t_vec2				vec2i_div(t_vec2 a, t_vec2 b);
t_vec2				vec2i_div_scal(t_vec2 a, int constant);
t_vec2				vec2i_scale(t_vec2 a, int b);
t_vec2				vec2i_invert(t_vec2 a);
t_vec2				vec2i_normalize(t_vec2 a);
t_vec2				vec2i_clamp(t_vec2 a, t_vec2 min, t_vec2 max);
double				vec2i_length(t_vec2 a);
double				vec2i_dist(t_vec2 a, t_vec2 b);

t_vec2f				vec2f(double x, double y);
t_vec2f				vec2f_add(t_vec2f a, t_vec2f b);
t_vec2f				vec2f_sub(t_vec2f a, t_vec2f b);
t_vec2f				vec2f_mul(t_vec2f a, t_vec2f b);
t_vec2f				vec2f_mul_scal(t_vec2f a, double constant);
t_vec2f				vec2f_div(t_vec2f a, t_vec2f b);
t_vec2f				vec2f_div_scal(t_vec2f a, double constant);
t_vec2f				vec2f_scale(t_vec2f a, double b);
t_vec2f				vec2f_invert(t_vec2f a);
t_vec2f				vec2f_normalize(t_vec2f a);
t_vec2f				vec2f_clamp(t_vec2f a, t_vec2f min, t_vec2f max);
double				vec2f_length(t_vec2f a);
double				vec2f_dist(t_vec2f a, t_vec2f b);

t_vec3				vec3(double x, double y, double z);
t_vec3				vec3_add(t_vec3 a, t_vec3 b);
t_vec3				vec3_sub(t_vec3 a, t_vec3 b);
t_vec3				vec3_mul(t_vec3 a, t_vec3 b);
t_vec3				vec3_mul_scal(t_vec3 a, double constant);
t_vec3				vec3_div(t_vec3 a, t_vec3 b);
t_vec3				vec3_div_scal(t_vec3 a, double constant);
t_vec3				vec3_scale(t_vec3 a, double b);
t_vec3				vec3_invert(t_vec3 a);
t_vec3				vec3_normalize(t_vec3 a);
t_vec3				vec3_clamp(t_vec3 a, t_vec3 min, t_vec3 max);
double				vec3_length(t_vec3 a);
double				vec3_dist(t_vec3 a, t_vec3 b);

#endif
