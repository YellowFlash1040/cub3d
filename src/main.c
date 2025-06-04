/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:33:47 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/04 18:17:09 by akovtune         ###   ########.fr       */
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

void	handle_error(t_app *app, int err_code);

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
	exit_all(&data, 0);
	return (SUCCESS);
}

void handle_error(t_app *app, int err_code)
{
	print_err_msg(get_err_msg(err_code));
	if (app)
		destroy_app(&app);
}
