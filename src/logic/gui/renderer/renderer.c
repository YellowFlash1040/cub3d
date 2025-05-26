/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:40:56 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/26 15:43:21 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	render(t_app *app)
{
	mlx_loop_hook(app->mlx, render_frame, app);
}

void	render_frame(void *param)
{
	t_app		*app;
	t_player	*player;
	t_map		*map;

	app = (t_app *)param;
	player = app->game->player;
	map = app->game->map;
	clear_buffer(app->canvas->image);
	populate_rays(map, player);
	if (app->settings->is_minimap_visible)
		draw_minimap(app->canvas, map, player);
	draw_scene(app->canvas, player->camera);
}

void	clear_buffer(mlx_image_t *img)
{
	ft_bzero(img->pixels, img->width * img->height * sizeof(uint32_t));
}
