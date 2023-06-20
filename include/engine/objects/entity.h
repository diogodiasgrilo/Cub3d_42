/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:46:54 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 15:50:07 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include <engine/object.h>

typedef struct s_entity		t_entity;
typedef struct s_new_entity	t_new_entity;

struct s_new_entity
{
	t_new_object	obj;
};

struct s_entity
{
	t_list					*__components;
	t_object_a_comp			add_component;
	t_object_r_comp			remove_component;
	t_object_g_comp			get_component;
	t_object_h_comp			has_component;
	t_object_i_comp_f		is_component_frozen;

	void					(*update)(double delta_time);
	void					(*render)(double delta_time);

	t_identity_component	*(*get_identity)(void);
	t_transform				*(*get_transform)(void);

	const u_int32_t			*id;
	const char				*tag;
	const t_transform		*transform;

	t_vec3f					*(*get_position)(void);
	double					*(*get_rotation)(void);
	void					(*set_position)(t_vec3f position);
	void					(*set_rotation)(double rotation);

};

t_entity	*entity(void);
t_entity	*ent(void);
t_entity	*ethis(void);

t_entity	*new_entity(t_new_entity def);

#endif
