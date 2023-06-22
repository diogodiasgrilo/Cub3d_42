/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   profiler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:45:49 by martiper          #+#    #+#             */
/*   Updated: 2023/06/22 11:09:59 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "profiler.h"
#include "raycasting.h"

double	profiler_start(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == 0)
		return (time.tv_sec * 1e6 + time.tv_usec);
	return (0);
}

void	profiler_record(double handle, char *msg)
{
	double	now;
	double	diff;

	now = profiler_start();
	diff = now - handle;
	ft_printf("[%s] Time elapsed: %fms\n", msg, diff / 1000);
}
