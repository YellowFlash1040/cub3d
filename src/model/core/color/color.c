/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:53:30 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/31 16:18:55 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	get_color(t_channel r, t_channel g, t_channel b, t_channel a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

//percentage has to be a value within [0.0, 1.0]
t_color	darken_color(t_color color, double percentage)
{
	t_channel	r;
	t_channel	g;
	t_channel	b;
	t_channel	a;

	if (percentage > 1.0)
		percentage = 1.0;
	if (percentage < 0.0)
		percentage = 0.0;

	r = ((color >> 24) & 0xFF) * percentage;
	g = ((color >> 16) & 0xFF) * percentage;
	b = ((color >> 8) & 0xFF) * percentage;
	a = (color & 0xFF); // Preserve alpha

	color = (r << 24) | (g << 16) | (b << 8) | a;
	return (color);
}
