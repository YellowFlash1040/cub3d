/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:24:48 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/07 19:40:24 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall_drawing.h"

void	draw_horizontal_line(t_canvas *canvas, t_point point,
	int width, t_color color)
{
	int	i;

	i = 0;
	while (i < width)
	{
		draw_pixel(canvas, point.x, point.y, color);
		point.x++;
		i++;
	}
}

t_color	add_shadows(t_ray *ray, t_color color)
{
	double	max_visible;
	double	brightness;

	if (ray->hit_type == HORIZONTAL_HIT)
		color = darken_color(color, 0.7);
	max_visible = 800.0;
	brightness = 1.0 - ray->length / max_visible;
	if (brightness < 0.3)
		brightness = 0.3;
	color = darken_color(color, brightness);
	return (color);
}

/*
"max_visible" variable represents the maximum distance
at which a ray can see or affect the shading.

You can think of it as a "visibility range" or "shadow range".

If the ray length (distance from the viewpoint to the hit)
is equal to or greater than max_visible (ray->length >= max_visible),
the brightness should be minimal (darkest shadow).

If the ray length is 0 (very close),
brightness is at its maximum (no darkening).

The number 800 was chosen randomly
and represents the furthest visible distance.
*/

// t_color	add_shadows(t_ray *ray, t_color color)
// {
// 	// Darken if it's a HORIZONTAL hit
// 	if (ray->hit_type == HORIZONTAL_HIT)
// 		color = darken_color(color, 0.7); // 70% brightness

// 	// Distance-based shading
// 	double max_visible = 800.0;
// 	double brightness = 1.0 - ray->length / max_visible;
// 	if (brightness < 0.3)
// 		brightness = 0.3; // Never completely black

// 	color = darken_color(color, brightness);
// 	return (color);
// }
