/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:33:47 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/05 17:31:43 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:33:47 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/03 18:38:17 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "startup.h"

void		handle_error(t_app *app, int err_code);
// static int	copy_map(t_map *map, t_data *data);

int	main(int argc, char **argv)
{
	int		result;
	t_data	data;
	t_app	*app;

	check_input(&data, argc, argv);
	check_dir_map(&data);
	scrape_dir_map(&data);
	resize_map(&data);
	
	app = init_app();
	if (!app)
		return (handle_error(app, MALLOC_FAIL_ERR), MALLOC_FAIL_ERR);

	/*--------------------------------------------------------------*/
	t_map	*map;
	map = init_map();
	if (!map)
		return (handle_error(NULL, MALLOC_FAIL_ERR), MALLOC_FAIL_ERR);

	//Trying to get map
	//---------------------------------

	map->width = data.resize_map_size.x;
	map->height = data.resize_map_size.y;
	map->cells = data.resize_map;

	//---------------------------------

	t_settings	*settings;
	settings = init_settings();
	if (!settings)
		return (destroy_map(&map),
			handle_error(app, MALLOC_FAIL_ERR), MALLOC_FAIL_ERR);
	setup_settings(settings, &data);
	/*--------------------------------------------------------------*/

	free_all(&data, 0);

	result = startup(app, settings, map);
	if (result != SUCCESS)
	{
		if (!(app->game && app->game->map))
			destroy_map(&map);
		return (handle_error(app, result), result);
	}
	subscribe_to_keyboard_events(app);
	// subscribe_to_mouse_events(app);
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

// static int	copy_map(t_map *map, t_data *data)
// {
// 	int	result;
// 	int	x;
// 	int	y;

// 	result = build_map(map, map->width, map->height);
// 	if (result != SUCCESS)
// 		return (destroy_map(&map), MALLOC_FAIL_ERR);
// 	y = -1;
// 	while (++y < map->height)
// 	{
// 		x = -1;
// 		while (++x < map->width)
// 			map->cells[y][x] = data->resize_map[y][x];
// 	}
// 	return (SUCCESS);
// }
