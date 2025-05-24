/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:03:16 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/24 19:54:14 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

// Pythagorean theorem
// c² = a² + b²
// we need to find 'c'
// so we need to find a square root from a² + b²
double	find_distance(t_fpoint a, t_fpoint b)
{
	double	distance;
	double	dx;
	double	dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	distance = sqrt(dx * dx + dy * dy);
	return (distance);
}

/*
double	dx; // Difference in x-coordinates
double	dy; // Difference in y-coordinates
*/

t_vector	get_unit_vector(double angle)
{
	t_vector	vector;

	vector.x = cos(angle);
	vector.y = -sin(angle);
	return (vector);
}

// In Math (Unit Circle):
/*

(0,0) is at the center.

+x goes right.

+y goes up.

Angles increase counter-clockwise (CCW).

cos(θ) = horizontal movement (left/right).
sin(θ) = vertical movement (up/down).
*/

// In Screen Coordinates (MiniLibX):
/*
(0,0) is at the top-left corner.

+x still goes right ✅

+y goes down ❗️
-y goes up ❗️

So if you want to go up you have to subtract value from y

Angles increase ClockWise ❗️
unless you flip the value of delta_y using -sin()
*/
