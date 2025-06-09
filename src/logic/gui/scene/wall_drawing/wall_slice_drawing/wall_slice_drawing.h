/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_slice_drawing.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:15:18 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/07 19:33:06 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_SLICE_DRAWING_H
# define WALL_SLICE_DRAWING_H

# include "drawing.h"
# include "canvas.h"
# include "texture.h"
# include "ray.h"
# include "settings.h"
# include "angles.h"

typedef struct line_info
{
	int		width;
	int		height;
	int		original_height;
	t_point	canvas_pos;
}	t_line_info;

typedef struct texture_info
{
	int			x;
	double		y;
	double		step;
	t_texture	*texture;
}	t_texture_info;

void	draw_textured_wall_slice(t_canvas *canvas, t_ray *ray,
			t_texture *texture, int ray_index);
t_color	add_shadows(t_ray *ray, t_color color);
void	draw_horizontal_line(t_canvas *canvas, t_point point,
			int width, t_color color);

#endif
