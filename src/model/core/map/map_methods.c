/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:17:27 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/27 18:04:15 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	is_obstacle(t_map *map, int x, int y)
{
	if (x < 0 || x > map->width)
		return (true);
	if (y < 0 || y > map->height)
		return (true);
	if (map->cells[y][x] == WALL)
		return (true);
	if (map->cells[y][x] == CLOSED_DOOR)
		return (true);
	return (false);
}

bool	is_door(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->width)
		return (false);
	if (y < 0 || y >= map->height)
		return (false);
	if (map->cells[y][x] == CLOSED_DOOR)
		return (true);
	if (map->cells[y][x] == OPENED_DOOR)
		return (true);
	return (false);
}

void	toggle_door(t_map *map, int x, int y)
{
	if (map->cells[y][x] == OPENED_DOOR)
		map->cells[y][x] = CLOSED_DOOR;
	else if (map->cells[y][x] == CLOSED_DOOR)
		map->cells[y][x] = OPENED_DOOR;
}
