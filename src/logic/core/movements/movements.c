/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:25 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/02 15:15:34 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

void	move_player_forward(t_map *map, t_player *player, double delta_time)
{
	t_fpoint	new_position;
	double		distance;

	distance = MOVEMENT_SPEED * delta_time;
	new_position.x = player->position.x
		+ player->vertical_direction.x * distance;
	new_position.y = player->position.y
		+ player->vertical_direction.y * distance;
	move_if_possible(map, player, new_position);
}

void	move_player_backward(t_map *map, t_player *player, double delta_time)
{
	t_fpoint	new_position;
	double		distance;

	distance = MOVEMENT_SPEED * delta_time;
	new_position.x = player->position.x
		- player->vertical_direction.x * distance;
	new_position.y = player->position.y
		- player->vertical_direction.y * distance;
	move_if_possible(map, player, new_position);
}

void	move_player_left(t_map *map, t_player *player, double delta_time)
{
	t_fpoint	new_position;
	double		distance;

	distance = MOVEMENT_SPEED * delta_time;
	new_position.x = player->position.x
		- player->horizontal_direction.x * distance;
	new_position.y = player->position.y
		- player->horizontal_direction.y * distance;
	move_if_possible(map, player, new_position);
}

void	move_player_right(t_map *map, t_player *player, double delta_time)
{
	t_fpoint	new_position;
	double		distance;

	distance = MOVEMENT_SPEED * delta_time;
	new_position.x = player->position.x
		+ player->horizontal_direction.x * distance;
	new_position.y = player->position.y
		+ player->horizontal_direction.y * distance;
	move_if_possible(map, player, new_position);
}

void	move_if_possible(t_map *map, t_player *player, t_fpoint new_position)
{
	int	x;
	int	y;

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

/*
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
*/