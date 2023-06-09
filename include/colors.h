/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:02:23 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/09 18:45:52 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

typedef	struct	s_determine_color
{
	float	max_distance;
	float	min_distance;
    float	height;
	float	ratio;
    int		white;
    int		grey;
    int		red;
    int		green;
    int		blue;
}				t_determine_color;

# define DEFAULT	"\033[0;39m"
# define RED		"\033[0;91m"
# define GREEN		"\033[0;92m"
# define YELLOW		"\033[0;93m"
# define BLUE		"\033[0;94m"
# define MAGENTA	"\033[0;95m"
# define CYAN		"\033[0;96m"
# define WHITE		"\033[0;97m"
# define GREY		0x808080
# define BLACK		0x000000
# define NEWWHITE	0x00FFFFFF

#endif