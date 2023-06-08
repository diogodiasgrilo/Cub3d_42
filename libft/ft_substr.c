/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:44:15 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/05 20:05:45 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	m_allocator(char const *s, unsigned int start, unsigned long int len)
{
	unsigned long int	i;

	i = 0;
	s += start;
	while (*s++ && i < len)
		i++;
	return (i);
}

char	*error_allocator(void)
{
	char	*string;

	string = (char *)malloc((sizeof(char) * 1));
	if (!string)
		return (0);
	string[0] = '\0';
	return (string);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	unsigned long int	i;
	unsigned long int	l_len;
	int					allocate;
	char				*string;

	i = 0;
	l_len = (unsigned long int)len;
	if (start > (unsigned int)ft_strlen(s))
		return (error_allocator());
	allocate = m_allocator(s, start, l_len);
	string = (char *)malloc((sizeof(char) * allocate) + 1);
	if (!string)
		return (0);
	s += start;
	while (*s && i < l_len)
	{
		string[i] = *s++;
		i++;
	}
	string[i] = '\0';
	return (string);
}

// int main()
// {
//     char *a = "hola";

//     printf("%s\n", ft_substr(a, 0, 18446744073709551615));
// }
