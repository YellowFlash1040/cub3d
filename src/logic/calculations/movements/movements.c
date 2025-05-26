/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:25 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/26 18:55:01 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

void	move_player_forward(t_player *player)
{
	player->position.x += player->direction.x * STEP;
	player->position.y += player->direction.y * STEP;
	player->camera->position = player->position;
}

void	move_player_back(t_player *player)
{
	player->position.x -= player->direction.x * STEP;
	player->position.y -= player->direction.y * STEP;
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
