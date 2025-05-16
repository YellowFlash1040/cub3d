/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:18:46 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/16 17:57:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_handlers.h"
#include <stdio.h>

void	subscribe_to_keyboard_events(t_app *app)
{
	mlx_key_hook(app->client, &handle_key_pressed, app);
}

void	handle_key_pressed(mlx_key_data_t keydata, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (keydata.key == KEY_UP && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		// app->canvas->instances[0].y -= 10;
		move_player_up(app->game);
	}
	else if (keydata.key == KEY_DOWN && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		// app->canvas->instances[0].y += 10;
		move_player_down(app->game);
	}
	else if (keydata.key == KEY_LEFT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		// app->canvas->instances[0].x -= 10;
		move_player_left(app->game);
	}
	else if (keydata.key == KEY_RIGHT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		// app->canvas->instances[0].x += 10;
		move_player_right(app->game);
	}
	else if (keydata.key == KEY_CLOSE_WINDOW && keydata.action == MLX_PRESS)
	{
		mlx_close_window(app->client);
	}
}
