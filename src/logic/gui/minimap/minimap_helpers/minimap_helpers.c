/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:05:14 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/15 12:25:27 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_helpers.h"

t_point	scale_position(t_fpoint position)
{
	t_point	scaled_position;

	scaled_position.x = position.x * MINIMAP_CELL_SIZE / CELL_SIZE;
	scaled_position.y = position.y * MINIMAP_CELL_SIZE / CELL_SIZE;
	return (scaled_position);
}
/*
      mini_pos            pos
------------------  =  ----------
   MINI_CELL_SIZE       CELL_SIZE


       minimap     vs     game world
*/

void	apply_offset(t_point *point, t_point offset)
{
	point->x += offset.x;
	point->y += offset.y;
}

t_color	get_cell_color(t_map *map, int x, int y)
{
	t_color	color;

	if (map->cells[y][x] == WALL)
		color = WALL_COLOR;
	else if (map->cells[y][x] == CLOSED_DOOR)
		color = CLOSED_DOOR_COLOR;
	else if (map->cells[y][x] == OPENED_DOOR)
		color = OPENED_DOOR_COLOR;
	else
		color = EMPTY_SPACE_COLOR;
	return (color);
}

void	draw_cell(t_canvas *canvas, t_point	point, t_color color)
{
	t_size	size;

	size.width = MINIMAP_CELL_SIZE;
	size.height = MINIMAP_CELL_SIZE;
	draw_rectangle(canvas, point, size, color);
}

void	draw_grid(t_canvas *canvas, t_point point, t_size size,
	t_size cell_size)
{
	t_point	bottom_right_corner;
	t_point	start;
	t_point	end;

	bottom_right_corner.x = point.x + size.width;
	bottom_right_corner.y = point.y + size.height;
	start.x = point.x;
	start.y = point.y;
	end.y = bottom_right_corner.y;
	while (start.x <= bottom_right_corner.x)
	{
		end.x = start.x;
		draw_line(canvas, start, end, GRID_COLOR);
		start.x += cell_size.width;
	}
	start.x = point.x;
	start.y = point.y;
	end.x = bottom_right_corner.x;
	while (start.y <= bottom_right_corner.y)
	{
		end.y = start.y;
		draw_line(canvas, start, end, GRID_COLOR);
		start.y += cell_size.height;
	}
}

/*
//Draw vertical lines
	start.y = point.y;
	end.y = size.height;
	start.x = point.x;
	while (start.x <= size.width)
	{
		end.x = start.x;
		draw_line(canvas, start, end, EMPTY_SPACE_COLOR);
		start.x += cell_size.width;
	}

//Draw horizontal lines
	start.x = point.x;
	end.x = size.width;
	start.y = point.y;
	while (start.y <= size.height)
	{
		end.y = start.y;
		draw_line(canvas, start, end, EMPTY_SPACE_COLOR);
		start.y += cell_size.height;
	}
*/
