/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipped_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:51:55 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 16:52:01 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clipped_minimap.h"

void	draw_clipped_map(t_canvas *canvas, t_point start_point, t_map *map,
	t_player *player)
{
	t_corners	corners;
	t_point		cell;
	t_color		color;
	t_point		offset;

	corners = find_corners((t_size){map->width, map->height},
			player->position);
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
