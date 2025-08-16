/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullsize_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:50:07 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 17:19:49 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fullsize_minimap.h"

void	draw_fullsize_minimap(t_canvas *canvas, t_map *map, t_player *player)
{
	t_size	cell_size;
	t_size	map_size;
	t_point	position;

	cell_size = (t_size){MINIMAP_CELL_SIZE, MINIMAP_CELL_SIZE};
	map_size.width = map->width * cell_size.width;
	map_size.height = map->height * cell_size.height;
	position.x = WINDOW_WIDTH / 2 - map_size.width / 2;
	position.y = WINDOW_HEIGHT / 2 - map_size.height / 2;
	draw_map(canvas, position, map);
	draw_rays(canvas, position, player->camera);
	draw_grid(canvas, position, map_size, cell_size);
	draw_player(canvas, position, player);
}
