/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_material.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:29:28 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 16:20:56 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_MATERIAL_H
# define C_MATERIAL_H

#include <engine/materials.h>

typedef struct s_material_component	t_material_component;

struct s_material_component
{
	t_engine_material	*mat;
	t_engine_sprite		*sprite;
	void				(*set)(char *name);
	void				(*update)(double delta_time);
};

t_material_component	*new_material_component(t_engine_material *mat);

#endif
