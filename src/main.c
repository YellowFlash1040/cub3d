/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:33:47 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/31 17:49:18 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "window.h"
#include "canvas.h"
#include "renderer.h"
#include "event_handlers.h"

#include "app_builder.h"
#include "game_builder.h"
#include "map_builder.h"
#include "player_builder.h"
#include "camera_builder.h"
#include "textures_builder.h"

#include "settings_setup.h"
#include "textures_setup.h"
#include "player_setup.h"
#include "camera_setup.h"

void	fill_fake_map(t_map *map);
void	print_map(t_map* map);

void	handle_error(t_app *app, int err_code);

int	main(int argc, char **argv)
{
	int		result;
	t_app	*app;

	(void)argc;
	(void)argv;
	printf("Hello from cub3d\n");
	app = init_app();
	result = connect_to_display(&app->mlx);
	if (result != SUCCESS)
		return (handle_error(app, result), result);
	result = create_canvas(app->mlx, &app->canvas, (t_size){WINDOW_WIDTH, WINDOW_HEIGHT}, (t_point){0});
	if (result != SUCCESS)
		return (handle_error(app, result), result);
	
	/*--------------------------------------------------------------*/
	build_app(app);

	t_game* game = app->game;
	build_game(game);
	
	build_map(game->map, 8, 8);
	fill_fake_map(game->map);
	print_map(game->map);

	setup_settings(app->settings);

	t_player* player = game->player;
	build_player(player);
	setup_player(player, app->settings);
	build_camera(player->camera, RAYS_COUNT);
	setup_camera(player->camera, app->settings);

	build_textures(app->textures);
	setup_textures(app->textures, app->settings);
	/*--------------------------------------------------------------*/

	subscribe_to_keyboard_events(app);
	render(app);
	keep_app_running(app->mlx);
	destroy_app(&app);
	return (SUCCESS);
}

void handle_error(t_app *app, int err_code)
{
	print_err_msg(get_err_msg(err_code));
	destroy_app(&app);
}

void	fill_fake_map(t_map *map)
{
	// int digital_map[] =
	// {
	// 	1,1,1,1,1,1,1,1,
	// 	1,0,1,0,0,0,0,1,
	// 	1,0,1,0,0,0,0,1,
	// 	1,0,1,0,0,0,0,1,
	// 	1,0,0,0,0,0,0,1,
	// 	1,0,0,0,0,1,0,1,
	// 	1,0,0,0,0,0,0,1,
	// 	1,1,1,1,1,1,1,1
	// };

	int digital_map[] =
	{
		1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,1,
		1,0,1,0,0,1,1,1,
		1,1,0,0,0,1,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,1,0,1,
		1,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1
	};

	int map_size = (int)sizeof(digital_map) / sizeof(digital_map[0]);
	int width = 8;


	int x, y;
	for (int i = 0; i < map_size; i++)
	{
		y = i / width;
		x = i - y * width;
		map->cells[y][x] = digital_map[i] + '0';
	}
}

void print_map(t_map* map)
{
	for (int y = 0; y < map->height; y++)
	{
		for (int x = 0; x < map->width; x++)
		{
			if (map->cells[y][x] == '0')
				printf("\033[0;34m%c \033[0m", map->cells[y][x]);
			else
				printf("\033[0;31m%c \033[0m", map->cells[y][x]);
		}
		printf("\n");
	}
}
