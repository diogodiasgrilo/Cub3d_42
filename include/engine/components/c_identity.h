/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_identity.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:19:34 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 14:11:39 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_IDENTITY_H
# define C_IDENTITY_H

# include <std.h>

typedef struct s_identity_component	t_identity_component;

struct s_identity_component
{
	u_int32_t	id;
	char		*tag;
};

t_identity_component	*new_identity_component(const char *tag);

#endif
