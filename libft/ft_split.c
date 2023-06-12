/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:43:14 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/05 14:43:16 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_separator(char string_c, char c)
{
	if (string_c == c)
		return (1);
	return (0);
}

static int	count_strings(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && check_separator(str[i], c))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !check_separator(str[i], c))
			i++;
	}
	return (count);
}

static int	ft_strlen_sep(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !check_separator(str[i], c))
		i++;
	return (i);
}

static char	*ft_word(char *str, char c)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = ft_strlen_sep(str, c);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		i;

	i = 0;
	strings = (char **)malloc(sizeof(char *) * (count_strings((char *)s, c)
				+ 1));
	if (!strings)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && check_separator(*s, c))
			s++;
		if (*s != '\0')
		{
			strings[i] = ft_word((char *)s, c);
			i++;
		}
		while (*s && !check_separator(*s, c))
			s++;
	}
	strings[i] = 0;
	return (strings);
}

// int	main(void)
// {
// 	char	**split;
// 	int		i;

// 	split = ft_split("hello!", 32:' ');
// 	i = -1;
// 	while (split[++i] != 0)
// 		printf("[%d]: %s\n", i, split[i]);
// }
