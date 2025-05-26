/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:55:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/25 15:56:22 by akovtune         ###   ########.fr       */
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
	return (settings);
}

void	destroy_settings(t_settings **settings_ref)
{
	t_settings	*settings;

	if (!settings_ref || !*settings_ref)
		return ;
	settings = *settings_ref;
	free(settings);
	*settings_ref = NULL;
}
