/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_compatibility.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:46:11 by martiper          #+#    #+#             */
/*   Updated: 2023/06/09 12:48:21 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CROSS_COMPATIBILITY_H
# define CROSS_COMPATIBILITY_H

typedef enum e_cc_os
{
	OS_LINUX,
	OS_DARWIN,
	OS_WINDOWS
}				t_cc_os;

# ifndef __OS__
#  define __OS__ OS_LINUX
# endif

# define IS_LINUX __OS__ == OS_LINUX
# define IS_DARWIN __OS__ == OS_DARWIN
# define IS_WINDOWS __OS__ == OS_WINDOWS

#endif
