/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:12:18 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 15:32:32 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENT_H
# define COMPONENT_H

# include <std.h>

typedef struct s_component	t_component;
typedef enum e_comp_labels	t_comp_labels;

enum e_comp_labels
{
	COMPONENT_IDENTITY,
	COMPONENT_TRANSFORM,
	COMPONENT_CAMERA,
	COMPONENT_COLLIDER,
	COMPONENT_PHYSICS,
	COMPONENT_MATERIAL
};

struct s_component
{
	u_int64_t		__id;
	t_comp_labels	__tag;
	bool			__frozen;
	void			*__data;
};

#endif
