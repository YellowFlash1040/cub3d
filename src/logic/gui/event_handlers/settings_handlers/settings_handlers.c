/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:29:15 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/04 16:29:43 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings_handlers.h"

void	toggle_minimap(t_settings *settings)
{
	settings->is_minimap_visible = !settings->is_minimap_visible;
}
