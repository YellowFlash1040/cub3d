/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:22:44 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/23 16:29:04 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "angles.h"

bool	is_almost_zero(double value)
{
	return (fabs(value) < EPSILON);
}

bool	is_horizontal_angle(double angle)
{
	return (is_almost_zero(angle) || is_almost_zero(M_PI - angle));
}

bool	is_vertical_angle(double angle)
{
	return (is_almost_zero(M_PI_2 - angle) || is_almost_zero(M_3_PI_2 - angle));
}

void	normalize_angle(double *angle_ref)
{
	const double	two_pi = 2.0 * M_PI;
	double			angle;

	if (!angle_ref)
		return ;
	angle = *angle_ref;
	angle = fmod(angle, two_pi);
	if (angle < 0)
		angle += two_pi;

	if (angle < EPSILON || two_pi - angle < EPSILON)
		angle = 0.0;

	*angle_ref = angle;
}

/*
	fmod(x, y) - function from math.h
	which is equivalent to
	x % y
	for floating point numbers

	fabs(x) - function from math.h
	which is equivalent to
	|x|
	in math
	for floating numbers

	abs(x)
	is the |x| for integers
*/

/*
	// keep the angle between -2pi and 2pi
	angle = fmod(angle, two_pi);

	//keep the angle between 0 and 2pi
	if (angle < 0)
		angle += two_pi;

	// if the angle is pretty close to 2pi or 0
	// (which is the same for us but not for a computer)
	// make it 0
	if (angle < EPSILON || fabs(angle - two_pi) < EPSILON)
		angle = 0.0;
*/
