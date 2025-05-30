/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:56:51 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/29 17:08:53 by akovtune         ###   ########.fr       */
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
	if (app->textures)
		destroy_textures(&app->textures);
	if (app->canvas)
		destroy_canvas(&app->canvas);
	mlx_terminate(app->mlx);
	free(app);
	*app_ref = NULL;
}
