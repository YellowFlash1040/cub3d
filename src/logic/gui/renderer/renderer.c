/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:40:56 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/15 12:30:14 by akovtune         ###   ########.fr       */
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

void	render_frame(void *param)
{
	t_app		*app;
	t_player	*player;
	t_game		*game;

	app = (t_app *)param;
	game = app->game;
	player = app->game->player;
	clear_buffer(app->canvas->image);
	update_animations(app->animations);
	update_textures(app->textures, app->animations);
	populate_rays(game->map, player);
	draw_scene(app->canvas, player->camera, game, app->textures);
	if (app->settings->is_minimap_visible)
		draw_fullsize_minimap(app->canvas, game->map, player);
	if (app->settings->is_clipped_minimap_visible)
		draw_clipped_minimap(app->canvas, game->map, player);
}

void	clear_buffer(mlx_image_t *img)
{
	ft_bzero(img->pixels, img->width * img->height * sizeof(uint32_t));
}
