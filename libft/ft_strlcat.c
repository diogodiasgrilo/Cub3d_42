/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:43:37 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/05 14:43:39 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	changer(char *dst, const char *src)
{
	int	i;
	int	index;

	i = 0;
	index = ft_strlen(dst);
	while (src[i])
		dst[index++] = src[i++];
}

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	dst_len;
	int	src_len;
	int	i;
	int	sub;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	sub = ft_strlen(dst);
	i = -1;
	if (dstsize == 0)
		return (ft_strlen(src));
	else if (dstsize < 0)
	{
		changer(dst, src);
		return (dst_len + src_len);
	}
	if (dst_len < dstsize)
	{
		while (++i < dstsize - sub - 1 && *src)
			dst[dst_len++] = *src++;
		dst[dst_len] = '\0';
	}
	else
		return (dstsize + src_len);
	return (ft_strlen(dst) + ft_strlen(src));
}
