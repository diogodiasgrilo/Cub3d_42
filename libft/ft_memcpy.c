/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:42:42 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/06 08:33:55 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int		i;
	char	*c_dst;
	char	*c_src;

	i = 0;
	c_dst = (char *)dst;
	c_src = (char *)src;
	if (c_dst == NULL && c_src == NULL)
		return (NULL);
	while (i < n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return ((void *)c_dst);
}
