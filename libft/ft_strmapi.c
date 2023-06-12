/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:43:51 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/05 14:43:53 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		length;
	char	*changed;

	i = 0;
	length = ft_strlen((char *)s);
	changed = (char *)malloc((sizeof(char) * length) + 1);
	if (!changed || !*f)
		return (0);
	while (s[i] != '\0')
	{
		changed[i] = f(i, s[i]);
		i++;
	}
	changed[i] = '\0';
	return (changed);
}
