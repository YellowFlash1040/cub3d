/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:06:08 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/08 11:36:50 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STARTUP_H
# define STARTUP_H

# include "canvas.h"
# include "event_handlers.h"
# include "renderer.h"
# include "window.h"

# include "app_builder.h"
# include "camera_builder.h"
# include "canvas_builder.h"
# include "game_builder.h"
# include "map_builder.h"
# include "player_builder.h"
# include "textures_builder.h"

# include "camera_setup.h"
# include "player_setup.h"
# include "settings_setup.h"
# include "textures_setup.h"

int	startup(t_app *app, t_map *map);

#endif
