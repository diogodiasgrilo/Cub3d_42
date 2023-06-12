/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:43:42 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/04 09:20:24 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int	ft_strlcpy(char *dst, const char *src, \
		unsigned long int dstsize)
{
	unsigned long int	i;

	i = 0;
	if (dstsize <= 0)
		return (ft_strlen(src));
	while (src && src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src && src[i])
		i++;
	return (i);
}
