/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setup.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:57:00 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/31 17:35:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_SETUP_H
# define PLAYER_SETUP_H

# include "player.h"
# include "settings.h"
# include "errors.h"
# include "geometry.h"

void	setup_player(t_player *player, t_settings *settings);

#endif
