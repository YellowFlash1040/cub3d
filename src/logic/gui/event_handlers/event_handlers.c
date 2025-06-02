/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:18:46 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/02 14:26:22 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_handlers.h"

static void	handle_movement(mlx_t *mlx, mlx_key_data_t keydata, t_game *game);
static void	handle_rotation(mlx_t *mlx, mlx_key_data_t keydata, t_game *game);
static void	toggle_minimap(t_settings *settings);

void	subscribe_to_keyboard_events(t_app *app)
{
	mlx_key_hook(app->mlx, &handle_key_pressed, app);
}

void	handle_key_pressed(mlx_key_data_t keydata, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (is_movement_key(keydata.key))
		handle_movement(app->mlx, keydata, app->game);
	else if (is_rotation_key(keydata.key))
		handle_rotation(app->mlx, keydata, app->game);
	else if (keydata.key == KEY_CLOSE_WINDOW && keydata.action == MLX_PRESS)
		mlx_close_window(app->mlx);
	else if (keydata.key == KEY_TOGGLE_MINIMAP && keydata.action == MLX_PRESS)
		toggle_minimap(app->settings);
}

static void	handle_movement(mlx_t *mlx, mlx_key_data_t keydata, t_game *game)
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

static void	handle_rotation(mlx_t *mlx, mlx_key_data_t keydata, t_game *game)
{
	if (!(keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		return ;
	if (keydata.key == KEY_ROTATE_LEFT)
		rotate_player_left(game->player, mlx->delta_time);
	else if (keydata.key == KEY_ROTATE_RIGHT)
		rotate_player_right(game->player, mlx->delta_time);
}

static void	toggle_minimap(t_settings *settings)
{
	settings->is_minimap_visible = !settings->is_minimap_visible;
}
