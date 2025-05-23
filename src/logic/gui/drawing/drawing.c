/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:22:57 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/23 13:23:03 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawing.h"

void	draw_rectangle(t_canvas *canvas, t_point top_left, t_size size,
	t_color color)
{
	int	x;
	int	y;
	int	x_end;
	int	y_end;

	x_end = top_left.x + size.width;
	y_end = top_left.y + size.height;
	y = top_left.y;
	while (y < y_end)
	{
		x = top_left.x;
		while (x < x_end)
		{
			mlx_put_pixel(canvas->image, x, y, color);
			x++;
		}
		y++;
	}
}

// Needs to be rewritten by me
void	draw_pixel(t_canvas *canvas, int x, int y, t_color color)
{
	if (x < 0 || x >= canvas->size.width || y < 0 || y >= canvas->size.height)
		return;
	mlx_put_pixel(canvas->image, x, y, color);
}

void	draw_line(t_canvas *canvas, t_point start, t_point end, t_color color)
{
	int dx = abs(end.x - start.x);
	int dy = abs(end.y - start.y);
	int sx = (start.x < end.x) ? 1 : -1;
	int sy = (start.y < end.y) ? 1 : -1;
	int err = dx - dy;

	while (1)
	{
		draw_pixel(canvas, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break;
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			start.x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			start.y += sy;
		}
	}
}
