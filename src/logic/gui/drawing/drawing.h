/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:13:31 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/26 15:52:37 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H

# include "canvas.h"
# include "color.h"

typedef struct line_params
{
	int	dx;
	int	dy;
	int	step_x;
	int	step_y;
	int	error;
}	t_line_params;

void	draw_rectangle(t_canvas *canvas, t_point top_left, t_size size,
			t_color color);
void	draw_line(t_canvas *canvas, t_point start, t_point end, int width,
			t_color color);
void	draw_pixel(t_canvas *canvas, int x, int y, t_color color);

#endif
