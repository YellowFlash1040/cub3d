/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:33:47 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/16 17:50:58 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "window.h"
#include "canvas.h"
#include "map_builder.h"
#include <stdio.h>
#include "minimap.h"
#include "event_handlers.h"

void	ft_randomize(void *param);
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
	result = connect_to_display(&app->client);
	if (result != SUCCESS)
		return (print_err_msg(get_err_msg(result)), result);
	result = create_canvas(app, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (result != SUCCESS)
		return (print_err_msg(get_err_msg(result)), result);
	
	/*--------------------------------------------------------------*/
	app->game = init_game();
	app->game->map = init_map();
	build_map(app->game->map, 5, 5);
	fill_fake_map(app->game->map);
	print_map(app->game->map);
	// draw_minimap(app->canvas, app->game->map);
	/*--------------------------------------------------------------*/

	subscribe_to_keyboard_events(app);
	render(app);
	keep_app_running(app->client);
	destroy_app(&app);
	return (SUCCESS);
}

void	fill_fake_map(t_map *map)
{
	int digital_map[] =
	{
		1,1,1,1,1,
		1,0,0,0,1,
		1,0,0,0,1,
		1,0,0,0,1,
		1,1,1,1,1
	};

	int width = 5;

	int x, y;
	for (int i = 0; i < (int)sizeof(digital_map); i++)
	{
		y = i / width;
		x = i - y * width;
		map->cells[x][y] = digital_map[i] + '0';
	}
}

void print_map(t_map* map)
{
	for (int y = 0; y < map->height; y++)
	{
		for (int x = 0; x < map->width; x++)
		{
			printf("%c ", map->cells[y][x]);
		}
		printf("\n");
	}
}
