/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:33:47 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/09 19:01:46 by akovtune         ###   ########.fr       */
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

int	setup_app_using_data(t_app **app_ref, t_data *data, t_map **map_out);
int	handle_error(t_app *app, int err_code);

int	main(int argc, char **argv)
{
	int		result;
	t_data	data;
	t_app	*app;
	t_map	*map;

	parse_all(&data, argc, argv);
	result = setup_app_using_data(&app, &data, &map);
	if (result != SUCCESS)
		return (handle_error(app, result));
	free_all(&data, 0);
	result = startup(app, map);
	if (result != SUCCESS)
	{
		if (!(app->game && app->game->map))
			destroy_map(&map);
		return (handle_error(app, result), result);
	}
	subscribe_to_keyboard_events(app);
	subscribe_to_mouse_events(app);
	result = render(app);
	if (result != SUCCESS)
		return (handle_error(app, result), result);
	keep_app_running(app->mlx);
	destroy_app(&app);
	return (SUCCESS);
}

int	handle_error(t_app *app, int err_code)
{
	print_err_msg(get_err_msg(err_code));
	if (app)
		destroy_app(&app);
	return (err_code);
}

int	setup_app_using_data(t_app **app_ref, t_data *data, t_map **map_out)
{
	t_app		*app;
	t_map		*map;
	t_settings	*settings;

	app = init_app();
	*app_ref = app;
	if (!app)
		return (free_all(data, 1), MALLOC_FAIL_ERR);
	map = init_map();
	*map_out = map;
	if (!map)
		return (free_all(data, 1), MALLOC_FAIL_ERR);
	map->width = data->resize_map_size.x;
	map->height = data->resize_map_size.y;
	map->cells = data->resize_map;
	settings = init_settings();
	if (!settings)
		return (free(map), free_all(data, 1), MALLOC_FAIL_ERR);
	app->settings = settings;
	setup_settings(settings, data);
	return (SUCCESS);
}
