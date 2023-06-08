/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:43:55 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/04 07:51:38 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	unsigned char	c1;
	unsigned char	c2;
	int				i;

	i = 0;
	if ((!s1 && !s2) || n == 0 || (!*s1 && !*s2))
		return (0);
	if (n < 0)
		return (-1);
	while (s1 && s2 && s1[i] == s2[i] && i < n - 1 && s1[i] && s2[i])
		i++;
	c1 = s1[i];
	c2 = s2[i];
	return (c1 - c2);
}
