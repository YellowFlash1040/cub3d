/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:25 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/18 16:01:51 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

int	move_player_up(t_player *player)
{
	player->position.x += player->delta_x;
	player->position.y += player->delta_y;
	return (SUCCESS);
}

int	move_player_down(t_player *player)
{
	player->position.x -= player->delta_x;
	player->position.y -= player->delta_y;
	return (SUCCESS);
}

int	move_player_left(t_player *player)
{
	player->angle -= 0.1;
	if (player->angle < 0)
		player->angle += 2 * M_PI;
	player->delta_x = cos(player->angle) * 5;
	player->delta_y = sin(player->angle) * 5;
	return (SUCCESS);
}

int	move_player_right(t_player *player)
{
	player->angle += 0.1;
	if (player->angle > 2 * M_PI)
		player->angle -= 2 * M_PI;
	player->delta_x = cos(player->angle) * 5;
	player->delta_y = sin(player->angle) * 5;
	return (SUCCESS);
}
