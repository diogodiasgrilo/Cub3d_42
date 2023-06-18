/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:56:57 by martiper          #+#    #+#             */
/*   Updated: 2023/06/18 23:34:26 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/parser.h"
#include <utils/log.h>
#include <context/context.h>

typedef t_engine_parser			t_parser;
typedef t_engine_parser_handle	t_handle;

char	*__engine_parser_handle_get_prop(char *prop);
bool	__engine_parser_handle_skip_to_list(void);
char	*__engine_parser_handle_get_next(void);
void	__engine_parser_handle_end(void);

t_handle	*__engine_parser_begin(char *path)
{
	t_parser	*parser;
	t_handle	*handle;

	parser = get_parser();
	if (!parser || parser->is_running())
		return (NULL);
	if (!path || !ft_str_endswith(path, PARSER_EXT))
		return (NULL);
	handle = ft_calloc(1, sizeof(t_handle));
	if (!handle)
		return (NULL);
	parser->curr = handle;
	handle->get_prop = __engine_parser_handle_get_prop;
	handle->skip_to_list = __engine_parser_handle_skip_to_list;
	handle->get_next = __engine_parser_handle_get_next;
	handle->end = __engine_parser_handle_end;
	handle->path = path;
	handle->fd = open(path, O_RDONLY);
	if (handle->fd < 0)
	{
		(logger())->error("Failed to open file %s for parsing: %s", \
			path, strerror(errno));
		return (handle->end(), NULL);
	}
	return (handle);
}
