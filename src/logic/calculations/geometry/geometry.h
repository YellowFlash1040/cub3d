/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:03:11 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/23 16:31:00 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include "fpoint.h"
# include "vector.h"
# include "angles.h"

double		find_distance(t_fpoint a, t_fpoint b);
t_vector	get_unit_vector(double angle);

#endif
