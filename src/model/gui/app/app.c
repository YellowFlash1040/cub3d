/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:56:51 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 16:59:58 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

t_app	*init_app(void)
{
	t_app	*app;

	app = (t_app *)malloc(sizeof(t_app));
	if (!app)
		return (NULL);
	app->mlx = NULL;
	app->game = NULL;
	app->canvas = NULL;
	app->settings = NULL;
	app->textures = NULL;
	app->animations = NULL;
	app->cursor_position = (t_point){0};
	return (app);
}

void	destroy_app(t_app **app_ref)
{
	t_app	*app;

	if (!app_ref || !*app_ref)
		return ;
	app = *app_ref;
	if (app->settings)
		destroy_settings(&app->settings);
	if (app->game)
		destroy_game(&app->game);
	if (app->canvas)
		destroy_canvas(&app->canvas);
	if (app->textures)
		destroy_textures(&app->textures);
	if (app->animations)
		destroy_animations(&app->animations);
	if (app->mlx)
		mlx_terminate(app->mlx);
	free(app);
	*app_ref = NULL;
}

int	build_app(t_app **app_ref)
{
	t_app	*app;

	if (!app_ref || !*app_ref)
		return (EMPTY_PTR_ERR);
	app = *app_ref;
	app->settings = init_settings();
	if (!app->settings)
		return (destroy_app(app_ref), MALLOC_FAIL_ERR);
	app->game = init_game();
	if (!app->game)
		return (destroy_app(app_ref), MALLOC_FAIL_ERR);
	app->canvas = init_canvas((t_size){WINDOW_WIDTH, WINDOW_HEIGHT});
	if (!app->canvas)
		return (destroy_app(app_ref), MALLOC_FAIL_ERR);
	app->textures = init_textures();
	if (!app->textures)
		return (destroy_app(app_ref), MALLOC_FAIL_ERR);
	app->animations = init_animations();
	if (!app->animations)
		return (destroy_app(app_ref), MALLOC_FAIL_ERR);
	app->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, false);
	if (!app->mlx)
		return (destroy_app(app_ref), MLX_ERR);
	return (SUCCESS);
}
