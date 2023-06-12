/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:28:33 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/05 15:03:31 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *s, long int *counter)
{
	int	i;

	i = -1;
	if (!s)
	{
		ft_putstr("(null)", counter);
		return ;
	}
	while (s[++i])
		ft_putchar(s[i], counter);
}
