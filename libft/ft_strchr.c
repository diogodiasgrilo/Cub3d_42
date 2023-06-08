/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:43:19 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/04 08:03:00 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	c1;

	i = 0;
	c1 = c;
	while (s[i] != '\0')
	{
		if (s[i] == c1)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c1)
		return ((char *)(s + i));
	return (0);
}
