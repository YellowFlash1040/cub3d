/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:11:37 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/02 20:55:32 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static void	draw_grid(t_canvas *canvas, t_map *map);

void	draw_minimap(t_canvas *canvas, t_map *map, t_player *player)
{
	draw_map(canvas, map);
	draw_rays(canvas, player->camera);
	draw_grid(canvas, map);
	draw_player(canvas, player);
}

static void	draw_grid(t_canvas *canvas, t_map *map)
{
	int		x;
	int		y;
	t_point	start;
	t_point	end;

	x = -1;
	start.y = 0;
	end.y = map->height * MINIMAP_CELL_SIZE;
	while (++x <= map->width)
	{
		start.x = x * MINIMAP_CELL_SIZE;
		end.x = start.x;
		draw_line(canvas, start, end, EMPTY_SPACE_COLOR);
	}
	y = -1;
	start.x = 0;
	end.x = map->width * MINIMAP_CELL_SIZE;
	while (++y <= map->height)
	{
		start.y = y * MINIMAP_CELL_SIZE;
		end.y = start.y;
		draw_line(canvas, start, end, EMPTY_SPACE_COLOR);
	}
}

// static void	draw_background(t_canvas *canvas, t_size map_size,
// 	t_color color)
// {
// 	t_point	point;
// 	t_size	size;

// 	point = (t_point){0};
// 	size.width = MINIMAP_CELL_SIZE * map_size.width;
// 	size.height = MINIMAP_CELL_SIZE * map_size.height;
// 	draw_rectangle(canvas, point, size, color);
// }
