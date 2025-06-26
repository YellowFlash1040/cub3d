/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_helpers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:07:57 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 17:11:02 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_HELPERS_H
# define MINIMAP_HELPERS_H

# include "drawing.h"
# include "game.h"
# include "rays.h"
# include "map_point.h"

typedef struct corners
{
	t_map_point	top_left;
	t_map_point	bottom_right;
}	t_corners;

t_corners	find_corners(t_size map_size, t_fpoint player_position);
t_color		get_cell_color(t_map *map, int x, int y);
t_point		scale_position(t_fpoint position);
void		apply_offset(t_point *point, t_point offset);
void		draw_cell(t_canvas *canvas, t_point	point, t_color color);
void		draw_grid(t_canvas *canvas, t_point point, t_size size,
				t_size cell_size);

#endif
