/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_drawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:00:20 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/07 17:00:30 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "surface_drawing.h"

void	draw_surface(t_canvas *canvas, t_surface *surface)
{
	t_point	position;
	t_size	size;

	position.x = GAME_SCREEN_X_POSITION;
	size.width = GAME_SCREEN_WIDTH;
	size.height = GAME_SCREEN_HEIGHT / 2;
	if (surface->type == CEILING)
	{
		position.y = GAME_SCREEN_Y_POSITION;
		draw_rectangle(canvas, position, size, surface->color);
	}
	else if (surface->type == FLOOR)
	{
		position.y = GAME_SCREEN_HEIGHT / 2;
		draw_rectangle(canvas, position, size, surface->color);
	}
}
