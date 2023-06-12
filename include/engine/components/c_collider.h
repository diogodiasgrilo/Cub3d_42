/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_collider.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:35:28 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 20:23:08 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_COLLIDER_H
# define C_COLLIDER_H

# include <std.h>
# include <engine/transform.h>
# include <engine/object.h>

typedef struct s_collider_component	t_collider_component;
typedef enum e_collider_type		t_collider_type;
typedef struct s_collision_compute	t_collision_compute;

enum e_collider_type
{
	COLLIDER_AABB
};

struct s_collision_compute {
	t_collider_component	*collider;
	t_transform_component	*transform;
};

struct s_collider_component
{
	t_collider_type		type;
	t_vec3f				size;
	bool				(*collides)(t_object *);
	void				(*update)(void);
	void				(*draw)(void);
};

t_collider_component	*new_collider_component(t_collider_type type);
#endif
