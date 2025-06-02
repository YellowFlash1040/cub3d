/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:40:56 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/02 12:23:13 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	render(t_app *app)
{
	mlx_loop_hook(app->mlx, render_frame, app);
}

// DELETE THIS CODE
#ifdef DEBUG_MODE
# include <stdio.h>
static void	print_player_position(t_app *app)
{
	t_fpoint position = app->game->player->position;
	printf("\033[H\033[Jx: %lf, y: %lf\n", position.x, position.y);
	double angle = app->game->player->camera->angle;
	printf("Angle: %lf\n", angle * (180 / M_PI));
}

static void draw_texture(void *canvas, int x_offset, int y_offset, t_texture *tex)
{
	uint32_t x, y;
	
	for (y = 0; y < tex->height; y++)
	{
		for (x = 0; x < tex->width; x++)
		{
			t_color color = get_texture_pixel(tex, x, y);
			draw_pixel(canvas, x_offset + x, y_offset + y, color);
		}
	}
}

static void show_textures(t_app *app)
{
	int x = WINDOW_WIDTH - CELL_SIZE;
	t_texture* texture;
	texture = app->textures->north_wall->texture;
	draw_texture(app->canvas, x, 0, texture);
	texture = app->textures->south_wall->texture;
	draw_texture(app->canvas, x, 64, texture);
	texture = app->textures->west_wall->texture;
	draw_texture(app->canvas, x, 128, texture);
	texture = app->textures->east_wall->texture;
	draw_texture(app->canvas, x, 192, texture);
}

#endif

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
	draw_scene(app->canvas, player->camera, app->textures);
	if (app->settings->is_minimap_visible)
		draw_minimap(app->canvas, map, player);
	
	
#ifdef DEBUG_MODE
	show_textures(app);
	print_player_position(app);
#endif
}

void	clear_buffer(mlx_image_t *img)
{
	ft_bzero(img->pixels, img->width * img->height * sizeof(uint32_t));
}
