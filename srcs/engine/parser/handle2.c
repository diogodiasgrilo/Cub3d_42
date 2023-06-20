/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:56:57 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 17:37:07 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/parser.h"
#include <utils/log.h>
#include <context/context.h>

typedef t_engine_parser			t_parser;
typedef t_engine_parser_handle	t_handle;

static t_handle	*curr(void)
{
	return (get_parser()->curr);
}

char	*__engine_parser_handle_get_prop(char *prop)
{
	char	*line;
	char	*val;

	if (!curr())
		return (NULL);
	line = curr()->get_next();
	while (line)
	{
		if (ft_str_startswith(line, prop))
		{
			val = ft_strchr(line, ':');
			if (!val)
			{
				free(line);
				continue ;
			}
			val = ft_strdup(val + 1);
			return (free(line), val);
		}
	}
	return (NULL);
}

bool	__engine_parser_handle_skip_to_list(void)
{
	char	*line;

	if (!curr())
		return (false);
	line = curr()->get_next();
	if (!line)
		return (false);
	while (line && ft_strncmp(line, "---", 3))
	{
		free(line);
		line = curr()->get_next();
	}
	free(line);
	return (true);
}

char	*__engine_parser_handle_get_next(void)
{
	char	*line;

	if (!curr())
		return (NULL);
	line = get_next_line(curr()->fd);
	return (line);
}

void	__engine_parser_handle_end(void)
{
	char	*line;

	if (!curr())
		return ;
	line = curr()->get_next();
	while (line)
	{
		free(line);
		line = curr()->get_next();
	}
	if (curr()->fd > 0)
		close(curr()->fd);
	free(curr());
	get_parser()->curr = NULL;
}
