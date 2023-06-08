/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:44:00 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/05 14:44:01 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*finder(const char *haystack, const char *needle)
{
	int	j;
	int	i;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (needle[j] == *(haystack + i + j) && needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, int len)
{
	int	i;
	int	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	else if (*haystack == '\0')
		return (0);
	else if (len < 0)
		return (finder(haystack, needle));
	while (i < len && haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (needle[j] == *(haystack + i + j) && i + j < len && needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}

// int main()
// {
//     char *a = "Hi hello";
//     char *b = "H";

//     printf("%s\n", ft_strnstr(a, b, 9));
// }
