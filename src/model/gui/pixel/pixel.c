/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:21:15 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 19:21:58 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pixel.h"

t_color	get_pixel_color(t_pixel	*pixel)
{
	t_channel	r;
	t_channel	g;
	t_channel	b;
	t_channel	a;

	r = pixel[0];
	g = pixel[1];
	b = pixel[2];
	a = pixel[3];
	return (r << 24 | g << 16 | b << 8 | a);
}
