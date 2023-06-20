/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 23:11:32 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 17:52:13 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIALS_H
# define MATERIALS_H

# include <std.h>
# include <engine/sprites/store.h>

# define MATERIALS_PATH "assets/textures/"

typedef struct s_engine_materials	t_engine_materials;
typedef struct s_engine_material	t_engine_material;

struct s_engine_material
{
	char			*name;
	u_int32_t		count;
	t_engine_sprite	**sprites;
	int				animator_duration;
};

struct s_engine_materials
{
	t_list				*lst;
	t_engine_material	*(*get)(char *name, bool load);
};

t_engine_materials	*get_materials(void);
void				engine_materials_destroy_material(t_engine_material *mat);

#endif
