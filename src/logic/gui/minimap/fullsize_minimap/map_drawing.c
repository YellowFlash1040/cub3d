/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:56:23 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 15:38:17 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	draw_map(t_canvas *canvas, t_point point, t_map *map)
{
	int		x;
	int		y;
	t_color	color;
	t_point	offset;

	y = 0;
	offset.y = point.y;
	while (y < map->height)
	{
		x = 0;
		offset.x = point.x;
		while (x < map->width)
		{
			color = get_cell_color(map, x, y);
			draw_cell(canvas, offset, color);
			x++;
			offset.x += MINIMAP_CELL_SIZE;
		}
		y++;
		offset.y += MINIMAP_CELL_SIZE;
	}
}
