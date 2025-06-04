/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction_handlers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:31:38 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/04 19:33:29 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interaction_handlers.h"

static t_direction	get_direction(double angle);
static t_point		get_cell(t_fpoint position, t_direction direction);

void	handle_door_interaction(t_map *map, t_player *player)
{
	t_direction	direction;
	t_point		cell;

	direction = get_direction(player->camera->angle);
	cell = get_cell(player->position, direction);
	if (is_door(map, cell.x, cell.y))
		toggle_door(map, cell.x, cell.y);
}

static t_direction	get_direction(double angle)
{
	angle = angle * (180.0 / M_PI);
	if ((angle >= 0 && angle < 45) || (angle >= 315 && angle < 360))
		return (RIGHT);
	else if (angle >= 45 && angle < 135)
		return (UP);
	else if (angle >= 135 && angle < 225)
		return (LEFT);
	else if (angle >= 225 && angle < 315)
		return (DOWN);
	return (DIRECTION_NONE);
}

static t_point	get_cell(t_fpoint position, t_direction direction)
{
	t_point	cell;

	cell.x = position.x / CELL_SIZE;
	cell.y = position.y / CELL_SIZE;
	if (direction == UP)
		cell.y--;
	else if (direction == DOWN)
		cell.y++;
	else if (direction == LEFT)
		cell.x--;
	else if (direction == RIGHT)
		cell.x++;
	return (cell);
}
