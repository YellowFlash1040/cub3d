/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:55:51 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 17:09:55 by akovtune         ###   ########.fr       */
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
# include "ft_string.h"
# include "color.h"
# include "fpoint.h"

# define SETTINGS_INIT_ERR 1

// # define DEBUG_MODE

typedef struct settings
{
	t_fpoint	player_position;
	double		camera_fov;
	double		camera_angle;
	bool		is_minimap_visible;
	bool		is_clipped_minimap_visible;
	bool		prev_clipped_minimap_state;
	t_color		ceiling_color;
	t_color		floor_color;
	t_string	north_wall_filepath;
	t_string	south_wall_filepath;
	t_string	west_wall_filepath;
	t_string	east_wall_filepath;
	t_string	door_filepath;
}	t_settings;

t_settings	*init_settings(void);
void		destroy_settings(t_settings **settings_ref);

#endif
