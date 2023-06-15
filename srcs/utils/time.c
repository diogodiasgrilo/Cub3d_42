/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:29:00 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 18:43:26 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/time.h"

double	now(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL) == 0)
		return (t.tv_sec * 1000 + t.tv_usec / 1000);
	return (0);
}

struct timeval	get_timer(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == 0)
		return (time);
	return ((struct timeval){0, 0});
}
