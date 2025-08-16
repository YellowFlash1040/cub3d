/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:06:08 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 17:48:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STARTUP_H
# define STARTUP_H

# include "window.h"
# include "canvas.h"
# include "renderer.h"
# include "event_handlers.h"
# include "configuration.h"

# include "game_setup.h"
# include "player_setup.h"
# include "camera_setup.h"
# include "textures_setup.h"
# include "animations_setup.h"

int	startup(t_app **app_ref, t_configuration *config);

#endif
