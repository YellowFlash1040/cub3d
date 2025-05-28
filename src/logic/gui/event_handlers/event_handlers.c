/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:18:46 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/28 14:41:33 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_handlers.h"

void	subscribe_to_keyboard_events(t_app *app)
{
	mlx_key_hook(app->mlx, &handle_key_pressed, app);
}

void	handle_key_pressed(mlx_key_data_t keydata, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (keydata.key == KEY_UP
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_player_forward(app->game->map, app->game->player);
	else if (keydata.key == KEY_DOWN
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_player_back(app->game->map, app->game->player);
	else if (keydata.key == KEY_LEFT
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		rotate_player_left(app->game->player);
	else if (keydata.key == KEY_RIGHT
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		rotate_player_right(app->game->player);
	else if (keydata.key == KEY_CLOSE_WINDOW
		&& keydata.action == MLX_PRESS)
		mlx_close_window(app->mlx);
	else if (keydata.key == KEY_TOGGLE_MINIMAP
		&& keydata.action == MLX_PRESS)
		app->settings->is_minimap_visible = !app->settings->is_minimap_visible;
}
