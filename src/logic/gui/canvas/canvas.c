/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:40:56 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/16 17:43:05 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

int	create_canvas(t_app *app, int width, int height)
{
	int			result;
	mlx_image_t	*image;
	mlx_t		*mlx;

	mlx = app->client;
	image = mlx_new_image(mlx, width, height);
	if (!image)
		return (mlx_close_window(mlx), MLX_ERR);
	app->canvas = image;
	result = mlx_image_to_window(mlx, image, 0, 0);
	if (result == -1)
		return (mlx_close_window(mlx), MLX_ERR);
	return (SUCCESS);
}

void render(t_app *app)
{
	mlx_loop_hook(app->client, refresh_canvas, app);
}

#include <stdio.h>

void refresh_canvas(void* param)
{
	t_app	*app;

	app = (t_app *)param;

	printf("x: %d, y: %d\n", app->game->player_position.x, app->game->player_position.y);
	draw_minimap(app->canvas, app->game);
}
