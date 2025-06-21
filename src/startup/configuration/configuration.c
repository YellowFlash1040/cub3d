/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:56:37 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/21 12:56:30 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration.h"

t_configuration	*init_configuration(void)
{
	t_configuration	*configuration;

	configuration = (t_configuration *)malloc(sizeof(t_configuration));
	if (!configuration)
		return (NULL);
	configuration->player_position = (t_fpoint){0};
	configuration->camera_angle = 0;
	configuration->ceiling_color = (t_color){0};
	configuration->floor_color = (t_color){0};
	configuration->textures = NULL;
	configuration->animations = NULL;
	configuration->map = NULL;
	configuration->npcs = NULL;
	configuration->npc_count = 0;
	return (configuration);
}

void	destroy_configuration(t_configuration **configuration_ref,
	bool full_destruction)
{
	t_configuration	*configuration;

	if (!configuration_ref || !*configuration_ref)
		return ;
	configuration = *configuration_ref;
	if (configuration->textures)
		destroy_string_array(&configuration->textures);
	if (configuration->animations)
		destroy_string_array(&configuration->animations);
	if (full_destruction && configuration->map)
		destroy_map(&configuration->map);
	if (full_destruction && configuration->npcs)
		free(configuration->npcs);
	free(configuration);
	*configuration_ref = NULL;
}
