/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:37:54 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/26 13:09:36 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int size, int type)
{
	unsigned long int	i;
	unsigned long int	l_size;
	unsigned long int	l_type;
	char				*memory;

	i = 0;
	l_type = type;
	l_size = size;
	memory = malloc(l_size * l_type);
	if (!memory)
		return (0);
	while (i < (l_size * l_type))
	{
		memory[i] = '\0';
		i++;
	}
	return (memory);
}
