/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:40:56 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 13:15:43 by akovtune         ###   ########.fr       */
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
		draw_minimap(app->canvas, map, player);
	// t_fpoint position = app->game->player->position;
	// printf("x: %lf; y: %lf\n", position.x, position.y);
}

void	clear_buffer(mlx_image_t *img)
{
	ft_bzero(img->pixels, img->width * img->height * sizeof(uint32_t));
}
