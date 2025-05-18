/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:13:31 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/17 16:52:44 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H

# include "canvas.h"
# include "color.h"

void	draw_rectangle(t_canvas *canvas, t_point top_left, t_size size,
			t_color color);
void	draw_line(t_canvas *canvas, t_point start, t_point end, t_color color);

#endif
