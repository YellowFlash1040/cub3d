/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_corners.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:57:28 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 16:05:37 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static void	adjust_start(t_map_point *start);

t_corners	find_corners(t_size map, t_fpoint player_position)
{
	t_corners		corners;
	t_map_point		start;
	t_map_point		end;
	int				difference;

	start.y = player_position.y / CELL_SIZE - MINIMAP_VIEW_RADIUS;
	start.x = player_position.x / CELL_SIZE - MINIMAP_VIEW_RADIUS;
	adjust_start(&start);
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
	adjust_start(&start);
	corners = (t_corners){start, end};
	return (corners);
}

static void	adjust_start(t_map_point *start)
{
	if (start->x < 0)
		start->x = 0;
	if (start->y < 0)
		start->y = 0;
}
