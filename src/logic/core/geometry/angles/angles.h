/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:25:17 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/24 19:54:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANGLES_H
# define ANGLES_H

# include <stdbool.h>
# include "math.h"
# include "constants.h"

void	normalize_angle(double *angle_ref);
bool	is_almost_zero(double value);
bool	is_horizontal_angle(double angle);
bool	is_vertical_angle(double angle);
bool	angle_looks_up(double angle);
bool	angle_looks_down(double angle);
bool	angle_looks_right(double angle);
bool	angle_looks_left(double angle);

#endif
