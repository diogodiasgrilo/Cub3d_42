/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:11:25 by martiper          #+#    #+#             */
/*   Updated: 2023/06/10 18:58:28 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORE_H
# define STORE_H

# include "sprite.h"

typedef t_list	t_sprite_store;

t_sprite_store	*get_sprite_store(void);
t_sprite		*get_sprite(char *path);

#endif
