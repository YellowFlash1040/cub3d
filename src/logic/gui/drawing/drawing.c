/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:22:57 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/24 19:47:01 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawing.h"

static int	determine_step(int start, int end);

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

// Bresenham's Line Algorithm
void	draw_line(t_canvas *canvas, t_point start, t_point end, t_color color)
{
	t_line_params	lp;
	int				error_times_two;

	lp.dx = abs(end.x - start.x);
	lp.dy = abs(end.y - start.y);
	lp.step_x = determine_step(start.x, end.x);
	lp.step_y = determine_step(start.y, end.y);
	lp.error = lp.dx - lp.dy;
	while (true)
	{
		draw_pixel(canvas, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		error_times_two = 2 * lp.error;
		if (error_times_two > -lp.dy)
		{
			lp.error -= lp.dy;
			start.x += lp.step_x;
		}
		if (error_times_two < lp.dx)
		{
			lp.error += lp.dx;
			start.y += lp.step_y;
		}
	}
}

void	draw_pixel(t_canvas *canvas, int x, int y, t_color color)
{
	if (x < 0 || x >= canvas->size.width || y < 0 || y >= canvas->size.height)
		return ;
	mlx_put_pixel(canvas->image, x, y, color);
}

static int	determine_step(int start, int end)
{
	if (start < end)
		return (1);
	return (-1);
}
