/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:57:41 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 14:27:53 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <engine/transform.h>
# include <engine/component.h>
# include <engine/components/all.h>
# include <std.h>

typedef struct s_object		t_object;
typedef struct s_new_object	t_new_object;
typedef enum e_object_types	t_object_types;

struct s_new_object
{
	size_t			size;
	char			*tag;
	bool			empty_transform;
	t_vec3f			position;
	double			rotation;
};

typedef bool				(*t_object_a_comp)(t_comp_labels label, void *data, bool frozen);
typedef bool				(*t_object_r_comp)(t_comp_labels label);
typedef void				*(*t_object_g_comp)(t_comp_labels label);
typedef bool				(*t_object_h_comp)(t_comp_labels label);
typedef bool				(*t_object_i_comp_f)(t_comp_labels label);

struct s_object
{
	t_list					*__components;
	t_object_a_comp			add_component;
	t_object_r_comp			remove_component;
	t_object_g_comp			get_component;
	t_object_h_comp			has_component;
	t_object_i_comp_f		is_component_frozen;

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

t_object	*object(void);
t_object	*obj(void);
t_object	*this(void);

t_object  *new_object(t_new_object definition);

#endif
