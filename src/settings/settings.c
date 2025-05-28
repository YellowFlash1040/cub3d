/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:55:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/28 18:08:17 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings.h"

t_settings	*init_settings(void)
{
	t_settings	*settings;

	settings = (t_settings *)malloc(sizeof(t_settings));
	if (!settings)
		return (NULL);
	settings->is_minimap_visible = true;
	settings->ceiling = NULL;
	settings->floor = NULL;
	settings->north_wall = NULL;
	settings->south_wall = NULL;
	settings->west_wall = NULL;
	settings->east_wall = NULL;
	return (settings);
}

void	destroy_settings(t_settings **settings_ref)
{
	t_settings	*settings;

	if (!settings_ref || !*settings_ref)
		return ;
	settings = *settings_ref;
	if (settings->ceiling)
		destroy_surface(&settings->ceiling);
	if (settings->floor)
		destroy_surface(&settings->floor);
	if (settings->north_wall)
		destroy_wall(&settings->north_wall);
	if (settings->south_wall)
		destroy_wall(&settings->south_wall);
	if (settings->west_wall)
		destroy_wall(&settings->west_wall);
	if (settings->east_wall)
		destroy_wall(&settings->east_wall);
	free(settings);
	*settings_ref = NULL;
}
