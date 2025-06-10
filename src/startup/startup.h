/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:06:08 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 17:17:50 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STARTUP_H
# define STARTUP_H

# include "window.h"
# include "canvas.h"
# include "renderer.h"
# include "event_handlers.h"

# include "settings_setup.h"
# include "player_setup.h"
# include "camera_setup.h"
# include "textures_setup.h"

int	startup(t_app *app, t_map *map);

#endif
