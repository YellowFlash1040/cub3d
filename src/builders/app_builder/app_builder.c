/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:57:30 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/03 18:00:32 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app_builder.h"

static void	destroy_temp(t_app *app);

int	build_app(t_app *app)
{
	if (!app)
		return (EMPTY_PTR_ERR);
	app->settings = init_settings();
	if (!app->settings)
		return (destroy_temp(app), MALLOC_FAIL_ERR);
	app->game = init_game();
	if (!app->game)
		return (destroy_temp(app), MALLOC_FAIL_ERR);
	app->textures = init_textures();
	if (!app->textures)
		return (destroy_temp(app), MALLOC_FAIL_ERR);
	app->canvas = init_canvas((t_size){WINDOW_WIDTH, WINDOW_HEIGHT});
	if (!app->canvas)
		return (destroy_temp(app), MALLOC_FAIL_ERR);
	app->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, false);
	if (!app->mlx)
		return (destroy_temp(app), MLX_ERR);
	return (SUCCESS);
}

static void	destroy_temp(t_app *app)
{
	if (!app)
		return ;
	if (app->settings)
		destroy_settings(&app->settings);
	if (app->game)
		destroy_game(&app->game);
	if (app->textures)
		destroy_textures(&app->textures);
	if (app->canvas)
		destroy_canvas(&app->canvas);
	if (app->mlx)
		mlx_terminate(app->mlx);
}
