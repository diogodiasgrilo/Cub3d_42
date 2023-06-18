/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:42:54 by martiper          #+#    #+#             */
/*   Updated: 2023/06/18 22:59:13 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define PARSER_EXT ".c3d"
# include <std.h>

typedef struct s_engine_parser				t_engine_parser;
typedef struct s_engine_parser_handle		t_engine_parser_handle;
typedef enum e_engine_parser_handle_state	t_engine_parser_handle_state;

enum e_engine_parser_handle_state
{
	PARSER_HANDLE_PROPS,
	PARSER_HANDLE_LIST
};

struct s_engine_parser_handle
{
	t_engine_parser_handle_state	state;
	char							*path;
	int								fd;
	char							*(*get_prop)(char *prop);
	bool							(*skip_to_list)(void);
	char							*(*get_next)(void);
	void							(*end)(void);
};

struct s_engine_parser
{
	t_engine_parser_handle	*curr;
	t_engine_parser_handle	*(*begin)(char *path);
	bool					(*is_running)(void);
	void					(*shutdown)(void);
};

t_engine_parser	*get_parser(void);

#endif
