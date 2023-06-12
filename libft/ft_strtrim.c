/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:44:11 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/05 14:44:12 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_trim_front(char *s1, char *set, int x)
{
	int	i;
	int	count;
	int	gate;

	gate = 1;
	count = 0;
	while (gate)
	{
		gate = 0;
		i = 0;
		while (set[i])
		{
			if (set[i] == s1[x])
			{
				count++;
				gate = 1;
			}
			i++;
		}
		x++;
	}
	return (count);
}

static int	ft_find_trim_end(char *s1, char *set, int x)
{
	int	i;
	int	count;
	int	gate;

	gate = 1;
	count = 0;
	while (s1[x] != '\0')
		x++;
	x--;
	while (gate)
	{
		gate = 0;
		i = 0;
		while (set[i])
		{
			if (set[i++] == s1[x])
			{
				count++;
				gate = 1;
			}
		}
		x--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			len;
	const char	*start;
	const char	*end;
	int			trimmed_len;
	char		*result;

	len = ft_strlen(s1);
	start = s1;
	end = s1 + len - 1;
	start += ft_find_trim_front((char *)s1, (char *)set, 0);
	end -= ft_find_trim_end((char *)s1, (char *)set, 0);
	trimmed_len = end - start + 1;
	if (trimmed_len < 0)
		trimmed_len = 0;
	result = malloc(trimmed_len + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, start, trimmed_len + 1);
	result[trimmed_len] = '\0';
	return (result);
}

// int	main(void)
// {
// 	char s1[] = "          ";
// 	printf("%s\n", ft_strtrim(s1, " "));
// }
