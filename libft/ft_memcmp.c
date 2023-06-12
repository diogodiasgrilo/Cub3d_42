/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:42:36 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/11 12:04:09 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	int				i;
	unsigned char	c1;
	unsigned char	c2;
	char			*c_s1;
	char			*c_s2;

	i = 0;
	c_s1 = (char *)s1;
	c_s2 = (char *)s2;
	while (i < n)
	{
		if (c_s1[i] != c_s2[i])
		{
			c1 = (unsigned char) c_s1[i];
			c2 = (unsigned char) c_s2[i];
			return (c1 - c2);
		}
		i++;
	}
	return (0);
}
