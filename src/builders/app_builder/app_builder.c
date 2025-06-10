/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:57:30 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 16:36:34 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app_builder.h"

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
