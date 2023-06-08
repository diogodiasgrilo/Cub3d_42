/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:42:46 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/11 16:29:30 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, int len)
{
	char	*c_dst;
	char	*c_src;

	c_dst = (char *)dst;
	c_src = (char *)src;
	if (dst == src)
		return (dst);
	if (!dst && !src)
		return (0);
	if (dst > src)
		while (len--)
			c_dst[len] = c_src[len];
	else
		ft_memcpy(c_dst, c_src, len);
	return ((void *)c_dst);
}
