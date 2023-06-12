/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:53:44 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 12:13:43 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H
# define MAX_CONTEXTS 16

# include <stddef.h>

typedef enum e_context_ids
{
	CONTEXT_ID_OOP_INTERFACE
}	t_context_ids;

void	*get_context(int ctx_id, void *(*init)(void), void (*destroy)(void *));
void	*get_context_destructor(int ctx_id, void (*destroy)(void *));
void	destroy_context(int ctx_id);
void	destroy_all_contexts(void);

#endif
