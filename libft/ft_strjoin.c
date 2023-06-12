/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:43:32 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/05 14:43:34 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		t_length;

	t_length = 0;
	t_length += ft_strlen(s1);
	t_length += ft_strlen(s2);
	new_str = (char *)malloc((sizeof(char) * t_length + 1));
	if (!new_str)
		return (0);
	ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	ft_strlcat(new_str, s2, t_length + 1);
	return (new_str);
}

// int main()
// {
//     char	s1[] = "lorem ipsum";
// 	char	s2[] = "dolor sit amet";

//     printf("%s\n", ft_strjoin(s1, s2));
// }
