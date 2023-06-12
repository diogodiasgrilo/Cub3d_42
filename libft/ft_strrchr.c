/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:44:04 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/11 13:55:52 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	c1;
	char			*current;

	i = 0;
	c1 = c;
	current = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c1)
			current = ((char *)(s + i));
		i++;
	}
	if (s[i] == c1)
		return ((char *)(s + i));
	return (current);
}
