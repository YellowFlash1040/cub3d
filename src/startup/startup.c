/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:05:54 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 17:48:59 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "startup.h"

static int	build_data(t_app *app);
static int	setup_data(t_app *app, t_configuration *config);

int	startup(t_app **app_ref, t_configuration *config)
{
	int			result;
	t_app		*app;

	if (!app_ref || !config)
		return (EMPTY_PTR_ERR);
	app = init_app();
	if (!app)
		return (MALLOC_FAIL_ERR);
	*app_ref = app;
	result = build_app(app_ref);
	if (result != SUCCESS)
		return (result);
	result = build_data(app);
	if (result != SUCCESS)
		return (result);
	result = setup_data(app, config);
	if (result != SUCCESS)
		return (result);
	result = canvas_to_window(app->mlx, app->canvas);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

static int	build_data(t_app *app)
{
	int	result;

	result = build_game(&app->game);
	if (result != SUCCESS)
		return (result);
	result = build_canvas(&app->canvas, app->mlx);
	if (result != SUCCESS)
		return (result);
	result = build_textures(&app->textures);
	if (result != SUCCESS)
		return (result);
	result = build_player(&app->game->player);
	if (result != SUCCESS)
		return (result);
	result = build_camera(&app->game->player->camera, RAYS_COUNT);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

static int	setup_data(t_app *app, t_configuration *config)
{
	int	result;

	setup_game(app->game, config);
	setup_player(app->game->player, config);
	setup_camera(app->game->player->camera, app->settings, config);
	result = setup_textures(app->textures, config);
	if (result != SUCCESS)
		return (result);
	result = setup_animations(app->animations, config);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}
