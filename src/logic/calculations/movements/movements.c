/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:25 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/21 13:53:44 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"
#include <stdio.h>

static void	normalize_angle(double *angle_ref);
static void	update_player_deltas(t_player *player);

int	move_player_forward(t_player *player)
{
	player->position.x += player->delta_x * STEP;
	player->position.y += player->delta_y * STEP;
	return (SUCCESS);
}

int	move_player_back(t_player *player)
{
	player->position.x -= player->delta_x * STEP;
	player->position.y -= player->delta_y * STEP;
	return (SUCCESS);
}

int	rotate_player_left(t_player *player)
{
	player->angle += ROTATION_ANGLE;

	normalize_angle(&player->angle);
	update_player_deltas(player);
	printf("Angle: %.2f degrees\n", player->angle * (180.0 / M_PI));
	return (SUCCESS);
}

int	rotate_player_right(t_player *player)
{
	player->angle -= ROTATION_ANGLE;

	normalize_angle(&player->angle);
	update_player_deltas(player);
	printf("Angle: %.2f degrees\n", player->angle * (180.0 / M_PI));
	return (SUCCESS);
}

static void	normalize_angle(double *angle_ref)
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

static void	update_player_deltas(t_player *player)
{
	player->delta_x = cos(player->angle);
	player->delta_y = -sin(player->angle);
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