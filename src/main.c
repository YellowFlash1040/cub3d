/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:33:47 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/03 18:38:17 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "startup.h"

void	handle_error(t_app *app, int err_code);

#include <stdio.h>
void	fill_fake_map(t_map *map);
void	print_map(t_map* map);

int	main(int argc, char **argv)
{
	int		result;
	t_app	*app;

	(void)argc;
	(void)argv;
	printf("Hello from cub3d\n");
	
	app = init_app();
	if (!app)
		return (handle_error(app, MALLOC_FAIL_ERR), MALLOC_FAIL_ERR);

	/*--------------------------------------------------------------*/
	t_map	*map;
	map = init_map();
	if (!map)
		return (handle_error(NULL, MALLOC_FAIL_ERR), MALLOC_FAIL_ERR);
	result = build_map(map, 8, 8);
	if (result != SUCCESS)
		return (destroy_map(&map),
			handle_error(app, MALLOC_FAIL_ERR), MALLOC_FAIL_ERR);
	fill_fake_map(map);
	print_map(map);

	t_settings	*settings;
	settings = init_settings();
	if (!settings)
		return (destroy_map(&map),
			handle_error(app, MALLOC_FAIL_ERR), MALLOC_FAIL_ERR);
	setup_settings(settings);
	/*--------------------------------------------------------------*/

	result = startup(app, settings, map);
	if (result != SUCCESS)
	{
		if (!(app->game && app->game->map))
			destroy_map(&map);
		return (handle_error(app, result), result);
	}
	subscribe_to_keyboard_events(app);
	result = render(app);
	if (result != SUCCESS)
		return (handle_error(app, result), result);
	keep_app_running(app->mlx);
	destroy_app(&app);
	return (SUCCESS);
}

void handle_error(t_app *app, int err_code)
{
	print_err_msg(get_err_msg(err_code));
	if (app)
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
