/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:25 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/24 19:53:38 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"
#include <stdio.h>

int	move_player_forward(t_player *player)
{
	player->position.x += player->direction.x * STEP;
	player->position.y += player->direction.y * STEP;
	return (SUCCESS);
}

int	move_player_back(t_player *player)
{
	player->position.x -= player->direction.x * STEP;
	player->position.y -= player->direction.y * STEP;
	return (SUCCESS);
}

int	rotate_player_left(t_player *player)
{
	player->angle += ROTATION_ANGLE;
	normalize_angle(&player->angle);
	player->direction = get_unit_vector(player->angle);
	printf("Angle: %.2f degrees\n", player->angle * (180.0 / M_PI));
	return (SUCCESS);
}

int	rotate_player_right(t_player *player)
{
	player->angle -= ROTATION_ANGLE;
	normalize_angle(&player->angle);
	player->direction = get_unit_vector(player->angle);
	printf("Angle: %.2f degrees\n", player->angle * (180.0 / M_PI));
	return (SUCCESS);
}
