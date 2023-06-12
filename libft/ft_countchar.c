/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 08:01:36 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/05 14:54:04 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countchar(const char *s, int c)
{
	int				i;
	int				total;
	unsigned char	c1;

	i = 0;
	total = 0;
	c1 = c;
	while (s[i] != '\0')
	{
		if (s[i] == c1)
			total++;
		i++;
	}
	if (s[i] == c1)
		total++;
	return (total);
}
