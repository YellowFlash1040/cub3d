/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:25 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/16 17:33:42 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

int move_player_up(t_game *game)
{
	if (game->player_position.y >= STEP)
		game->player_position.y -= STEP;
	return (SUCCESS);
}

int move_player_down(t_game *game)
{
	if (game->player_position.y <= 1080)
		game->player_position.y += STEP;
	return (SUCCESS);
}

int move_player_left(t_game *game)
{
	if (game->player_position.x >= STEP)
		game->player_position.x -= STEP;
	return (SUCCESS);
}

int move_player_right(t_game *game)
{
	if (game->player_position.x <= 1920)
	game->player_position.x += STEP;
	return (SUCCESS);
}
