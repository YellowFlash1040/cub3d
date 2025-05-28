/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_builder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:04:01 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/28 18:06:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings_builder.h"

int	build_settings(t_settings *settings)
{
	if (!settings)
		return (EMPTY_PTR_ERR);
	settings->ceiling = init_surface();
	if (!settings->ceiling)
		return (destroy_settings(&settings), MALLOC_FAIL_ERR);
	settings->floor = init_surface();
	if (!settings->ceiling)
		return (destroy_settings(&settings), MALLOC_FAIL_ERR);
	settings->north_wall = init_wall();
	if (!settings->north_wall)
		return (destroy_settings(&settings), MALLOC_FAIL_ERR);
	settings->south_wall = init_wall();
	if (!settings->south_wall)
		return (destroy_settings(&settings), MALLOC_FAIL_ERR);
	settings->west_wall = init_wall();
	if (!settings->west_wall)
		return (destroy_settings(&settings), MALLOC_FAIL_ERR);
	settings->east_wall = init_wall();
	if (!settings->east_wall)
		return (destroy_settings(&settings), MALLOC_FAIL_ERR);
	return (SUCCESS);
}
