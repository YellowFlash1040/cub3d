/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:55:51 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/28 18:03:07 by akovtune         ###   ########.fr       */
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
# include "surface.h"
# include "wall.h"

# define SETTINGS_INIT_ERR 1

typedef struct settings
{
	bool		is_minimap_visible;
	t_surface	*ceiling;
	t_surface	*floor;
	t_wall		*north_wall;
	t_wall		*south_wall;
	t_wall		*west_wall;
	t_wall		*east_wall;
}	t_settings;

t_settings	*init_settings(void);
void		destroy_settings(t_settings **settings_ref);

#endif
