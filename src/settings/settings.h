/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:55:51 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 16:49:13 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include <stdlib.h>
# include <stdbool.h>
# include "key_bindings.h"
# include "window_settings.h"
# include "game_screen_settings.h"
# include "camera_settings.h"
# include "world_settings.h"
# include "minimap_settings.h"
# include "constants.h"

# define SETTINGS_INIT_ERR 1

// # define DEBUG_MODE

typedef struct settings
{
	double		camera_fov;
	bool		is_minimap_visible;
	bool		is_clipped_minimap_visible;
	bool		prev_clipped_minimap_state;
}	t_settings;

t_settings	*init_settings(void);
void		destroy_settings(t_settings **settings_ref);

#endif
