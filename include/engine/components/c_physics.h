/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_physics.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:30:57 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 15:40:37 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_PHYSICS_H
# define C_PHYSICS_H

#include <math/vec.h>

typedef struct s_physics_component	t_physics_component;

struct s_physics_component
{
	double	mass;
	t_vec3f	velocity;
	t_vec3f	acceleration;
	void	(*update)(double delta_time);
	void	(*apply_force)(t_vec3f direction, double force);
	void	(*halt)(void);
};

t_physics_component	*new_physics_component(double mass);

#endif
