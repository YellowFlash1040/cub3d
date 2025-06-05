/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:18:46 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/05 16:27:50 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_handlers.h"

void	subscribe_to_keyboard_events(t_app *app)
{
	mlx_key_hook(app->mlx, &handle_key_pressed, app);
}

void	subscribe_to_mouse_events(t_app *app)
{
	mlx_set_cursor_mode(app->mlx, MLX_MOUSE_DISABLED);
	mlx_cursor_hook(app->mlx, &handle_mouse_move, app);
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
	else if (keydata.key == KEY_TOGGLE_DOOR && keydata.action == MLX_PRESS)
		handle_door_interaction(app->game->map, app->game->player);
}
