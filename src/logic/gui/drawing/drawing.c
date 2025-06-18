/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:22:57 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/18 17:26:29 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawing.h"

static int	determine_step(int start, int end);
static void	clamp_bounds(t_size canvas_size, t_point *top_left,
				t_point *bottom_right);

void	draw_rectangle(t_canvas *canvas, t_point top_left, t_size size,
	t_color color)
{
	int		x;
	int		y;
	t_point	end;

	end.x = top_left.x + size.width;
	end.y = top_left.y + size.height;
	clamp_bounds(canvas->size, &top_left, &end);
	y = top_left.y;
	while (y < end.y)
	{
		x = top_left.x;
		while (x < end.x)
		{
			mlx_put_pixel(canvas->image, x, y, color);
			x++;
		}
		y++;
	}
}

static void	clamp_bounds(t_size canvas_size, t_point *top_left,
	t_point *bottom_right)
{
	if (top_left->x < 0)
		top_left->x = 0;
	if (top_left->y < 0)
		top_left->y = 0;
	if (bottom_right->x > canvas_size.width)
		bottom_right->x = canvas_size.width;
	if (bottom_right->y > canvas_size.height)
		bottom_right->y = canvas_size.height;
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
