/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   profiler.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:44:33 by martiper          #+#    #+#             */
/*   Updated: 2023/06/22 10:50:44 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROFILER_H
# define PROFILER_H

# include <time.h>
# include <sys/time.h>

double	profiler_start(void);
void	profiler_record(double handle, char *msg);

#endif
