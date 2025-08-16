/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:33:47 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/27 17:53:06 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:33:47 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/03 18:38:17 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "converter.h"
#include "startup.h"
#include "lifecycle.h"

int	handle_error(t_app *app, int err_code);

int	main(int argc, char **argv)
{
	int				result;
	t_data			data;
	t_app			*app;
	t_configuration	*configuration;

	parse_all(&data, argc, argv);
	configuration = convert_data_to_configuration(&data);
	if (!configuration)
		return (free_all(&data, 1), MALLOC_FAIL_ERR);
	free_all(&data, 0);
	result = startup(&app, configuration);
	if (result != SUCCESS)
		return (destroy_configuration(&configuration, true),
			handle_error(app, result));
	destroy_configuration(&configuration, false);
	subscribe_to_keyboard_events(app);
	subscribe_to_mouse_events(app);
	result = keep_app_running(app);
	if (result != SUCCESS)
		return (handle_error(app, result));
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
