/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:58:29 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 13:05:30 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include <math/vec.h>

typedef struct s_transform	t_transform;

struct s_transform
{
	t_vec3f	position;
	double	rotation;
};

#endif
