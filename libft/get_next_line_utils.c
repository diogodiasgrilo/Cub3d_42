/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:57:09 by ddias             #+#    #+#             */
/*   Updated: 2023/05/04 12:41:42 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_gnl(const char *str)
{
	int	index;

	index = 0;
	if (str == 0 || *str == '\0')
		return (0);
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char *)malloc((sizeof(char) * \
	(ft_strlen_gnl(s1) + ft_strlen_gnl(s2)) + 1));
	if (!new_str)
		return (0);
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	free(s1);
	while (*s2)
	{
		new_str[i++] = *s2;
		if (*s2++ == '\n')
			break ;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	ft_fixer_mover(char *buffer, int gate, int i)
{
	int	k;

	k = 0;
	if (gate)
	{
		while (buffer[i])
		{
			buffer[k++] = buffer[i];
			buffer[i++] = 0;
		}
	}
}

int	ft_tidy(char *buffer)
{
	int	gate;
	int	i;

	i = 0;
	gate = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			gate = 1;
			buffer[i++] = 0;
			break ;
		}
		buffer[i++] = 0;
	}
	ft_fixer_mover(buffer, gate, i);
	return (gate);
}
