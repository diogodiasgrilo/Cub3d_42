/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:42:31 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/06 08:40:06 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, int n)
{
	int					i;
	unsigned char		*s1;
	unsigned char		c1;

	i = -1;
	c1 = c;
	s1 = (unsigned char *)s;
	while (++i < n)
	{
		if (s1[i] == c1 || s1[i] == c)
			return ((void *)s1 + i);
	}
	return (0);
}
