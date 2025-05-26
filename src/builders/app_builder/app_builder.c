/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:57:30 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/25 16:01:35 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app_builder.h"

int	build_app(t_app *app)
{
	if (!app)
		return (EMPTY_PTR_ERR);
	app->settings = init_settings();
	if (!app->settings)
		return (MALLOC_FAIL_ERR);
	app->game = init_game();
	if (!app->game)
		return (destroy_settings(&app->settings), MALLOC_FAIL_ERR);
	return (SUCCESS);
}
