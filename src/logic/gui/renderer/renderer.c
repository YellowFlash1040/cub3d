/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:40:56 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 17:20:00 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

int	render(t_app *app)
{
	bool	success;

	success = mlx_loop_hook(app->mlx, render_frame, app);
	if (!success)
		return (MLX_ERR);
	return (SUCCESS);
}

#include <stdio.h>
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
	// draw_scene(app->canvas, player->camera, app->textures, app->game->map);
	if (app->settings->is_minimap_visible)
		draw_fullsize_minimap(app->canvas, map, player);
	if (app->settings->is_clipped_minimap_visible)
		draw_clipped_minimap(app->canvas, map, player);
}

void	clear_buffer(mlx_image_t *img)
{
	ft_bzero(img->pixels, img->width * img->height * sizeof(uint32_t));
}
