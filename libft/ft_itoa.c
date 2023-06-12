/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:38:56 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/07 10:41:00 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*allocator(int size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	str[size] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long long	ln;
	int			i;

	ln = n;
	i = len(ln);
	str = allocator(i--);
	if (!str)
		return (0);
	if (ln == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (ln < 0)
	{
		str[0] = '-';
		ln *= -1;
	}
	while (ln > 0)
	{
		str[i--] = (ln % 10) + 48;
		ln /= 10;
	}
	return (str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(42));
// }
