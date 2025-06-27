/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event_handlers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:21:52 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/27 17:49:59 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard_event_handlers.h"

void	handle_key_pressed(mlx_key_data_t keydata, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (keydata.key == KEY_CLOSE_WINDOW && keydata.action == MLX_PRESS)
		mlx_close_window(app->mlx);
	else if (keydata.key == KEY_TOGGLE_MINIMAP && keydata.action == MLX_PRESS)
		toggle_minimap(app->settings);
	else if (keydata.key == KEY_TOGGLE_CLIPPED_MINIMAP
		&& keydata.action == MLX_PRESS
		&& !app->settings->is_minimap_visible)
		toggle_clipped_minimap(app->settings);
	else if (keydata.key == KEY_TOGGLE_DOOR && keydata.action == MLX_PRESS)
		handle_door_interaction(app->game->map, app->game->player);
}

void	handle_keyboard(t_app *app)
{
	handle_movement(app->mlx, app->game);
	handle_rotation(app->mlx, app->game);
}
