/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:45:08 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 12:56:48 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <context/context.h>
#include "oop/oop.h"

static void	*__push(void *self)
{
	t_oop	*this;

	this = oop();
	if (!this)
		return (NULL);
	if (this->object)
		ft_lstadd_front(&this->objects, this->object);
	this->object = self;
	return (self);
}

static void	*__pop(void)
{
	void	*obj;
	t_oop	*this;

	this = oop();
	if (!this || !this->object)
		return (NULL);
	obj = this->object;
	if (this->objects)
	{
		this->object = this->objects->content;
		ft_lstremove(&this->objects, this->objects, NULL);
	}
	else
		this->object = NULL;
	return (obj);
}

static void	*__get(void)
{
	t_oop	*this;

	this = oop();
	if (!this)
		return (NULL);
	return (this->object);
}

static void	__flush(void)
{
	t_oop	*this;

	this = oop();
	if (!this)
		return ;
	ft_lstclear(&this->objects, NULL);
	this->object = NULL;
}

static void	*__constructor(void)
{
	t_oop	*oop;

	oop = ft_calloc(1, sizeof(t_oop));
	if (!oop)
		return (NULL);
	oop->push = __push;
	oop->pop = __pop;
	oop->get = __get;
	oop->flush = __flush;
	return (oop);
}

static void	__destructor(void *obj)
{
	t_oop	*oop;

	oop = obj;
	if (!oop)
		return ;
	if (oop->objects)
		ft_lstclear(&oop->objects, NULL);
}

t_oop	*get_oop_interface(void)
{
	return (get_context(\
		CONTEXT_ID_OOP_INTERFACE, \
		__constructor, \
		__destructor \
	));
}

t_oop	*get_oop(void)
{
	return (get_oop_interface());
}

t_oop	*oop(void)
{
	return (get_oop_interface());
}
