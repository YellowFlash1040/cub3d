/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:56:23 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/02 20:49:32 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static void	draw_cell(t_canvas *canvas, int x, int y, t_color color);

void	draw_map(t_canvas *canvas, t_map *map)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->cells[y][x] == '1')
				draw_cell(canvas, x, y, WALL_COLOR);
			else
				draw_cell(canvas, x, y, EMPTY_SPACE_COLOR);
		}
	}
}

static void	draw_cell(t_canvas *canvas, int x, int y, t_color color)
{
	t_point	point;
	t_size	size;

	point.x = x * MINIMAP_CELL_SIZE;
	point.y = y * MINIMAP_CELL_SIZE;
	size.width = MINIMAP_CELL_SIZE;
	size.height = MINIMAP_CELL_SIZE;
	draw_rectangle(canvas, point, size, color);
}
