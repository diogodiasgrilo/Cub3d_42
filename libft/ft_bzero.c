/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:37:49 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/05 14:37:50 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(char *s, int n)
{
	unsigned long int	i;
	unsigned long int	l_n;

	i = 0;
	l_n = n;
	while (i < l_n)
	{
		s[i] = '\0';
		i++;
	}
}

// int main()
// {
// 	int i;
// 	char tab[100];

// 	memset(tab, 'A', 100); tab[0] = 0;
// 	ft_bzero(tab, 42);
// 	i = 0;
// 	for (; i < 100 && tab[i] == 0; ++i)
// 		;
// 	printf("%d", i);
// }
