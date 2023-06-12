/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:57:10 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 23:40:20 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_mlx_image
{
	char	*data;
	void	*img;
	int		pix_index;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_mlx_image;

#endif
