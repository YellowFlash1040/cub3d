/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:05:54 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/03 18:36:22 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "startup.h"

static int	initialize_data(t_app *app);
static int	build_data(t_app *app);
static int	setup_data(t_app *app, t_settings *settings, t_map *map);

int	startup(t_app *app, t_settings *settings, t_map *map)
{
	int	result;

	app->settings = settings;
	result = initialize_data(app);
	if (result != SUCCESS)
		return (result);
	result = build_data(app);
	if (result != SUCCESS)
		return (result);
	result = setup_data(app, settings, map);
	if (result != SUCCESS)
		return (result);
	result = canvas_to_window(app->mlx, app->canvas);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

static int	initialize_data(t_app *app)
{
	app->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, false);
	if (!app->mlx)
		return (MLX_ERR);
	app->canvas = init_canvas((t_size){WINDOW_WIDTH, WINDOW_HEIGHT});
	if (!app->canvas)
		return (MALLOC_FAIL_ERR);
	app->textures = init_textures();
	if (!app->textures)
		return (MALLOC_FAIL_ERR);
	app->game = init_game();
	if (!app->game)
		return (MALLOC_FAIL_ERR);
	app->game->player = init_player();
	if (!app->game->player)
		return (MALLOC_FAIL_ERR);
	return (SUCCESS);
}

static int	build_data(t_app *app)
{
	int	result;

	result = build_canvas(app->canvas, app->mlx);
	if (result != SUCCESS)
		return (result);
	result = build_textures(app->textures);
	if (result != SUCCESS)
		return (result);
	result = build_player(app->game->player);
	if (result != SUCCESS)
		return (result);
	result = build_camera(app->game->player->camera, RAYS_COUNT);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

static int	setup_data(t_app *app, t_settings *settings, t_map *map)
{
	int	result;

	app->game->map = map;
	setup_player(app->game->player, settings);
	setup_camera(app->game->player->camera, settings);
	result = setup_textures(app->textures, settings);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}
