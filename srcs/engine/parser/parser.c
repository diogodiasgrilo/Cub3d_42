/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:49:11 by martiper          #+#    #+#             */
/*   Updated: 2023/06/18 23:33:37 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/parser.h"
#include <utils/log.h>
#include <context/context.h>

typedef t_engine_parser			t_parser;
typedef t_engine_parser_handle	t_handle;

t_handle	*__engine_parser_begin(char *path);

static bool	__is_running(void)
{
	return (get_parser()->curr != NULL);
}

static void	__shutdown(void)
{
	if (!get_parser()->is_running())
		return ;
	get_parser()->curr->end();
}

static void	*parser_create(void)
{
	t_parser	*parser;

	parser = ft_calloc(1, sizeof(t_parser));
	if (!parser)
		return (NULL);
	parser->begin = __engine_parser_begin;
	parser->is_running = __is_running;
	parser->shutdown = __shutdown;
	return (parser);
}

static void	parser_destroy(t_parser *parser)
{
	if (!parser)
		return ;
	if (parser->is_running())
		parser->shutdown();
	free(parser);
}

t_parser	*get_parser(void)
{
	return (get_context(\
		CONTEXT_ID_PARSER, \
		(t_context_construct_fn)parser_create, \
		(t_context_destruct_fn)parser_destroy \
	));
}
