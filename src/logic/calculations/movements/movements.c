/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:25 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/28 15:48:57 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

void	move_player_forward(t_map *map, t_player *player, double delta_time)
{
	t_fpoint	new_position;
	double		distance;
	int			x;
	int			y;

	distance = MOVEMENT_SPEED * delta_time;
	new_position.x = player->position.x + player->direction.x * distance;
	new_position.y = player->position.y + player->direction.y * distance;

	// Check X movement separately
	x = new_position.x / CELL_SIZE;
	y = player->position.y / CELL_SIZE;
	if (!is_obstacle(map, x, y))
		player->position.x = new_position.x;

	// Check Y movement separately
	x = player->position.x / CELL_SIZE;
	y = new_position.y / CELL_SIZE;
	if (!is_obstacle(map, x, y))
		player->position.y = new_position.y;

	player->camera->position = player->position;
}

void	move_player_back(t_map *map, t_player *player, double delta_time)
{
	t_fpoint	new_position;
	double		distance;
	int			x;
	int			y;

	distance = MOVEMENT_SPEED * delta_time;
	new_position.x = player->position.x - player->direction.x * distance;
	new_position.y = player->position.y - player->direction.y * distance;
	x = new_position.x / CELL_SIZE;
	y = player->position.y / CELL_SIZE;
	if (!is_obstacle(map, x, y))
		player->position.x = new_position.x;
	x = player->position.x / CELL_SIZE;
	y = new_position.y / CELL_SIZE;
	if (!is_obstacle(map, x, y))
		player->position.y = new_position.y;
	player->camera->position = player->position;
}

void	rotate_player_left(t_player *player)
{
	player->camera->angle += ROTATION_ANGLE;
	normalize_angle(&player->camera->angle);
	player->direction = get_unit_vector(player->camera->angle);
}

void	rotate_player_right(t_player *player)
{
	player->camera->angle -= ROTATION_ANGLE;
	normalize_angle(&player->camera->angle);
	player->direction = get_unit_vector(player->camera->angle);
}
