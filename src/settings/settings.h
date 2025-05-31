/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:55:51 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/31 17:01:38 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include <stdlib.h>
# include <stdbool.h>
# include "key_bindings.h"
# include "window_settings.h"
# include "camera_settings.h"
# include "world_settings.h"
# include "ft_string.h"
# include "color.h"
# include "fpoint.h"

# define SETTINGS_INIT_ERR 1

typedef struct settings
{
	t_fpoint	player_position;
	double		camera_fov;
	double		camera_angle;
	bool		is_minimap_visible;
	t_color		ceiling_color;
	t_color		floor_color;
	t_string	north_wall_filepath;
	t_string	south_wall_filepath;
	t_string	west_wall_filepath;
	t_string	east_wall_filepath;
}	t_settings;

t_settings	*init_settings(void);
void		destroy_settings(t_settings **settings_ref);

#endif
