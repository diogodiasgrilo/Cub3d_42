/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:12:22 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 16:10:20 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STD_H
# define STD_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <libft.h>
# include <mlx.h>
# include <math.h>
# include <time.h>
# include <sys/time.h>
# include <sys/file.h>
# include <sys/types.h>
# include <math/vec.h>
# include <errno.h>

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

#ifndef PI
# define PI M_PI
#endif
#ifndef TAU
# define TAU (2 * PI)
#endif

#endif
