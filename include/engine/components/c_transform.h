/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_transform.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:16:24 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 14:11:22 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_TRANSFORM_H
# define C_TRANSFORM_H

# include <engine/transform.h>

typedef t_transform	t_transform_component;

t_transform_component	*new_transform_component(t_vec3f position, double rotation);

#endif
