/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:28:04 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/05 15:03:21 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_helper(char *str, va_list ap, int i, long int *counter)
{
	if (str[i] == 'c')
		ft_putchar(va_arg(ap, int), counter);
	else if (str[i] == 's')
		ft_putstr(va_arg(ap, char *), counter);
	else if (str[i] == 'p')
		ft_hex_printer(va_arg(ap, unsigned long long int), 0, counter, 0);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr(va_arg(ap, int), counter);
	else if (str[i] == 'u')
		ft_putnbr(va_arg(ap, unsigned int), counter);
	else if (str[i] == 'x')
		ft_hex_printer(va_arg(ap, unsigned int), 1, counter, 0);
	else if (str[i] == 'X')
		ft_hex_printer(va_arg(ap, unsigned int), 1, counter, 1);
	else if (str[i] == '%')
		ft_putchar('%', counter);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	long int	i;
	long int	counter;

	i = 0;
	counter = 0;
	va_start(ap, str);
	if (!*str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ft_print_helper((char *)str, ap, ++i, &counter);
		else
			ft_putchar(str[i], &counter);
		i++;
	}
	va_end(ap);
	return (counter);
}

// int	main(void)
// {
// 	ft_printf(" %X \n", 11);
// 	printf(" %X ", 11);
// }
