/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:46:54 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 16:49:39 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <engine/objects/entity.h>
# include <engine/raycaster.h>

# define PLAYER_FOV FOV

typedef struct s_player		t_player;
typedef struct s_new_player	t_new_player;

struct s_new_player
{
	t_new_entity	ent;
};

struct s_player
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

	t_camera_component		*(*get_camera)(void);
	t_physics_component		*(*get_physics)(void);
};

t_player	*player(void);
t_player	*ply(void);
t_player	*pthis(void);

t_player	*new_player(t_new_player def);

#endif
