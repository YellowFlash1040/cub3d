/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:11:37 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 13:17:59 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	draw_minimap(t_canvas *canvas, t_map *map, t_player *player)
{
	t_size	map_size;
	t_point	position;
	t_size	cell_size;

	cell_size = (t_size){MINIMAP_CELL_SIZE, MINIMAP_CELL_SIZE};
	map_size.width = map->width * cell_size.width;
	map_size.height = map->height * cell_size.height;
	// position.x = WINDOW_WIDTH - map_size.width;
	// position.y = WINDOW_HEIGHT - map_size.height;
	position = (t_point){0};
	// position.x = WINDOW_WIDTH / 2 - map_size.width / 2;
	// position.y = WINDOW_HEIGHT / 2 - map_size.height / 2;
	draw_map(canvas, map, position);
	draw_rays(canvas, player->camera);
	draw_grid(canvas, position, map_size, cell_size);
	draw_player(canvas, player);

	if (MINIMAP_WIDTH <= map->width)
	{
		map_size.width = MINIMAP_WIDTH * cell_size.width;
		map_size.height = MINIMAP_HEIGHT * cell_size.height;
	}
	else
	{
		map_size.width = map->width * cell_size.width;
		map_size.height = map->height * cell_size.height;
	}
	// position = (t_point){0};
	position.x = WINDOW_WIDTH - map_size.width;
	position.y = WINDOW_HEIGHT - map_size.height;
	draw_miniminimap(canvas, position, map, player);
	draw_grid(canvas, position, map_size, cell_size);
	draw_miniplayer(canvas, position, player, (t_size){map->width, map->height});
	// draw_minirays(canvas, player->camera);

	// cell_size = (t_size){MINIMAP_CELL_SIZE, MINIMAP_CELL_SIZE};
	// map_size.width = map->width * cell_size.width;
	// map_size.height = map->height * cell_size.height;
	// position = (t_point){0};
	// draw_map(canvas, map, position);
	// draw_rays(canvas, player->camera);
	// draw_grid(canvas, position, map_size, cell_size);
	// draw_player(canvas, player);
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
