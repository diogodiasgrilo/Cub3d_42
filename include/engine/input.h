/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:46:50 by martiper          #+#    #+#             */
/*   Updated: 2023/06/16 14:28:27 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define INPUT_MAX 0xFFFF + 5

# include <std.h>

typedef struct s_engine_input			t_engine_input;
typedef enum e_engine_input_keycodes	t_engine_input_keycodes;

typedef struct s_engine_input_keycode	t_engine_input_keycode;

enum e_engine_input_keycodes
{
	INPUT_KEYCODE_ESCAPE = 65307,
	INPUT_KEYCODE_W = 119,
	INPUT_KEYCODE_A = 97,
	INPUT_KEYCODE_S = 115,
	INPUT_KEYCODE_D = 100,
	INPUT_KEYCODE_ARROW_UP = 65362,
	INPUT_KEYCODE_ARROW_LEFT = 65361,
	INPUT_KEYCODE_ARROW_DOWN = 65364,
	INPUT_KEYCODE_ARROW_RIGHT = 65363,
	INPUT_KEYCODE_E = 101,
	INPUT_KEYCODE_MOUSE_LEFT = 0xFFFF + 1,
	INPUT_KEYCODE_MOUSE_RIGHT = 0xFFFF + 2,
};

struct s_engine_input_keycode
{
	t_engine_input_keycodes	keycode;
	bool					pressed;
};

struct s_engine_input
{
	bool	keys[INPUT_MAX];
	t_vec2	mouse_pos;
	t_vec2	last_mouse_pos;
	t_vec2	mouse_delta;
	bool	(*is_pressed)(t_engine_input_keycodes);

	bool	(*is_mouse_moving)(void);
	void	(*set_mouse_pos)(t_vec2 pos);
	void	(*hide_mouse)(void);
	void	(*show_mouse)(void);

	void	(*start)(void);
	void	(*update)(double delta_time);
};

t_engine_input	*engine_input_init(void);

#endif
