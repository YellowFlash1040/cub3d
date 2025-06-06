/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:56:23 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 12:11:37 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static void	draw_cell(t_canvas *canvas, t_point	point, t_color color);

t_corners	find_corners(t_size map_size, t_fpoint player_position);
t_color		get_cell_color(t_map *map, int x, int y);

void	draw_miniminimap(t_canvas *canvas, t_point start_point, t_map *map, t_player *player)
{
	t_corners	corners;
	t_point		cell;
	t_color		color;
	t_point		offset;
	
	corners = find_corners((t_size){map->width, map->height}, player->position);
	cell.y = corners.top_left.y;
	offset.y = start_point.y;
	while (cell.y < corners.bottom_right.y)
	{
		cell.x = corners.top_left.x;
		offset.x = start_point.x;
		while (cell.x < corners.bottom_right.x)
		{
			color = get_cell_color(map, cell.x, cell.y);
			draw_cell(canvas, offset, color);
			cell.x++;
			offset.x += MINIMAP_CELL_SIZE;
		}
		cell.y++;
		offset.y += MINIMAP_CELL_SIZE;
	}
}

t_color	get_cell_color(t_map *map, int x, int y)
{
	t_color	color;

	if (map->cells[y][x] == WALL)
		color = WALL_COLOR;
	else if (map->cells[y][x] == CLOSED_DOOR)
		color = DOOR_COLOR;
	else
		color = EMPTY_SPACE_COLOR;
	return (color);
}

t_corners	find_corners(t_size map, t_fpoint player_position)
{
	t_corners	corners;
	t_point		start;
	t_point		end;
	int			difference;

	start.y = player_position.y / CELL_SIZE - MINIMAP_VIEW_RADIUS;
	start.x = player_position.x / CELL_SIZE - MINIMAP_VIEW_RADIUS;
	if (start.x < 0)
		start.x = 0;
	if (start.y < 0)
		start.y = 0;
	end.x = start.x + MINIMAP_WIDTH;
	end.y = start.y + MINIMAP_HEIGHT;
	if (end.x > map.width)
	{
		difference = end.x - map.width;
		end.x -= difference;
		start.x -= difference;
	}
	if (end.y > map.height)
	{
		difference = end.y - map.height;
		end.y -= difference;
		start.y -= difference;
	}
	if (start.x < 0)
		start.x = 0;
	if (start.y < 0)
		start.y = 0;
	corners.top_left = start;
	corners.bottom_right = end;
	return (corners);
}

void	draw_map(t_canvas *canvas, t_map *map, t_point point)
{
	int		x;
	int		y;
	t_color	color;
	t_point	offset;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->cells[y][x] == WALL)
				color = WALL_COLOR;
			else if (map->cells[y][x] == CLOSED_DOOR)
				color = DOOR_COLOR;
			else
				color = EMPTY_SPACE_COLOR;
			offset.x = point.x + x * MINIMAP_CELL_SIZE;
			offset.y = point.y + y * MINIMAP_CELL_SIZE;
			draw_cell(canvas, offset, color);
		}
	}
}

static void	draw_cell(t_canvas *canvas, t_point	point, t_color color)
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
