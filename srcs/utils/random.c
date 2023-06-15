/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:27:31 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 18:28:54 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/random.h"
#include <utils/time.h>

double	randf(void)
{
	srand(now());
	return (rand() / (double)RAND_MAX);
}

double	randf_range(double min, double max)
{
	return (randf() * (max - min) + min);
}

int	rand_range(int min, int max)
{
	return ((rand() % (max - min)) + min);
}
