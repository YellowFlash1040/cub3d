/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:25 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/18 15:54:35 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

int	move_player_up(t_player *player)
{
	if (player->position.y >= STEP)
		player->position.y -= STEP;
	return (SUCCESS);
}

int	move_player_down(t_player *player)
{
	if (player->position.y <= 1080)
		player->position.y += STEP;
	return (SUCCESS);
}

int	move_player_left(t_player *player)
{
	if (player->position.x >= STEP)
		player->position.x -= STEP;
	return (SUCCESS);
}

int	move_player_right(t_player *player)
{
	if (player->position.x <= 1920)
		player->position.x += STEP;
	return (SUCCESS);
}
