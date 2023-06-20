/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oop.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:21:01 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 15:19:25 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OOP_H
# define OOP_H

# include <std.h>

typedef struct s_oop_interface	t_oop_interface;
typedef t_oop_interface			t_oop;

struct s_oop_interface
{
	t_list	*objects;
	void	*object;
	void	*(*push)(void *self);
	void	*(*pop)(void *self);
	void	*(*get)(void);
	void	(*flush)(void);
};

t_oop	*get_oop(void);
t_oop	*get_oop_interface(void);
t_oop	*oop(void);

#endif
