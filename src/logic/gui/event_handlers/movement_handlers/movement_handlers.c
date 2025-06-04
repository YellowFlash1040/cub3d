/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:27:02 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/04 16:32:43 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement_handlers.h"

void	handle_movement(mlx_t *mlx, mlx_key_data_t keydata, t_game *game)
{
	if (!(keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		return ;
	if (keydata.key == KEY_MOVE_FORWARD)
		move_player_forward(game->map, game->player, mlx->delta_time);
	else if (keydata.key == KEY_MOVE_BACKWARD)
		move_player_backward(game->map, game->player, mlx->delta_time);
	else if (keydata.key == KEY_MOVE_LEFT)
		move_player_left(game->map, game->player, mlx->delta_time);
	else if (keydata.key == KEY_MOVE_RIGHT)
		move_player_right(game->map, game->player, mlx->delta_time);
}

void	handle_rotation(mlx_t *mlx, mlx_key_data_t keydata, t_game *game)
{
	if (!(keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		return ;
	if (keydata.key == KEY_ROTATE_LEFT)
		rotate_player_left(game->player, mlx->delta_time);
	else if (keydata.key == KEY_ROTATE_RIGHT)
		rotate_player_right(game->player, mlx->delta_time);
}
