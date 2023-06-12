/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strenlarge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 08:09:02 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/05 19:57:35 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strenlarge(char *str1, char *str2)
{
	char	*new_str;
	size_t	str1_len;
	size_t	str2_len;

	if (!str1)
	{
		new_str = ft_strdup((char *)str2);
		return (new_str);
	}
	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	new_str = (char *)malloc(sizeof(char) * (str1_len + str2_len + 1));
	if (!new_str)
		return (0);
	ft_strlcpy(new_str, str1, str1_len + str2_len + 1);
	ft_strlcat(new_str, str2, str1_len + str2_len + 1);
	free(str1);
	return (new_str);
}
