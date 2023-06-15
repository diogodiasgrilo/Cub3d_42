/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:28:41 by martiper          #+#    #+#             */
/*   Updated: 2023/06/15 13:59:44 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPPORT
# define SUPPORT

typedef enum e_gfx_os
{
	OS_LINUX,
	OS_DARWIN,
	OS_WINDOWS
}				t_gfx_os;

# ifndef __OS__
#  define __OS__ OS_LINUX
# endif

# define IS_LINUX (__OS__ == OS_LINUX)
# define IS_DARWIN (__OS__ == OS_DARWIN)
# define IS_WINDOWS (__OS__ == OS_WINDOWS)

#endif
