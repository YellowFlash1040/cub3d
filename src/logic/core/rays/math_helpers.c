/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:44:40 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/07 20:49:18 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

double	get_ray_angle_tan(double ray_angle)
{
	double	angle_tan;

	if (is_almost_zero(tan(ray_angle)))
		ray_angle += 0.0001;
	angle_tan = -tan(ray_angle);
	return (angle_tan);
}

double	get_ray_angle_cotan(double ray_angle)
{
	double	angle_cotan;

	if (is_almost_zero(tan(ray_angle)))
		ray_angle += 0.0001;
	angle_cotan = -1 / tan(ray_angle);
	return (angle_cotan);
}
