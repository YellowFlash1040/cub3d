/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:27:02 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/27 17:35:06 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"

void	handle_movement(mlx_t *mlx, t_game *game)
{
	if (mlx_is_key_down(mlx, KEY_MOVE_FORWARD))
		move_player_forward(game->map, game->player, mlx->delta_time);
	if (mlx_is_key_down(mlx, KEY_MOVE_BACKWARD))
		move_player_backward(game->map, game->player, mlx->delta_time);
	if (mlx_is_key_down(mlx, KEY_MOVE_LEFT))
		move_player_left(game->map, game->player, mlx->delta_time);
	if (mlx_is_key_down(mlx, KEY_MOVE_RIGHT))
		move_player_right(game->map, game->player, mlx->delta_time);
}

void	handle_rotation(mlx_t *mlx, t_game *game)
{
	if (mlx_is_key_down(mlx, KEY_ROTATE_LEFT))
		rotate_player_left(game->player, mlx->delta_time);
	else if (mlx_is_key_down(mlx, KEY_ROTATE_RIGHT))
		rotate_player_right(game->player, mlx->delta_time);
}
