/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipped_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:06:34 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 17:21:00 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clipped_minimap.h"

void	draw_clipped_minimap(t_canvas *canvas, t_map *map, t_player *player)
{
	t_size	cell_size;
	t_size	map_size;
	t_point	position;

	cell_size = (t_size){MINIMAP_CELL_SIZE, MINIMAP_CELL_SIZE};
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
	position = (t_point){0};
	draw_clipped_map(canvas, position, map, player);
	draw_grid(canvas, position, map_size, cell_size);
	draw_clipped_player(canvas, position, player,
		(t_size){map->width, map->height});
	// draw_minirays(canvas, player->camera);
}
