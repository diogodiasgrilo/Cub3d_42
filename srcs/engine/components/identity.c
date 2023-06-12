/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:12:40 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 14:13:41 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/components/c_identity.h"

t_identity_component	*new_identity_component(const char *tag)
{
	static u_int32_t		id;
	t_identity_component	*identity;

	identity = ft_calloc(1, sizeof(t_identity_component));
	if (!identity)
		return (NULL);
	identity->id = id++;
	identity->tag = ft_strdup(tag);
	return (identity);
}
