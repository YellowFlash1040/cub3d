/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:37:03 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/23 16:53:17 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "angles.h"

bool	angle_looks_up(double angle)
{
	return (angle < M_PI);
}

bool	angle_looks_down(double angle)
{
	return (angle > M_PI);
}

bool	angle_looks_right(double angle)
{
	return (angle < M_PI_2 || angle > M_3_PI_2);
}

bool	angle_looks_left(double angle)
{
	return (angle > M_PI_2 && angle < M_3_PI_2);
}
