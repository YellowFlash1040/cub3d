/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_interaction.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:31:09 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/27 18:10:03 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOR_INTERACTION_H
# define DOOR_INTERACTION_H

# include "map.h"
# include "player.h"
# include "direction.h"
# include "angles.h"
# include "world_settings.h"
# include "point.h"

void	handle_door_interaction(t_map *map, t_player *player);

#endif
