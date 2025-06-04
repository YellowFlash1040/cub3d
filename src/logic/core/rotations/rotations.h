/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:23:57 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/02 14:24:29 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATIONS_H
# define ROTATIONS_H

# include "settings.h"
# include "geometry.h"
# include "player.h"
# include "map.h"

void	rotate_player_left(t_player *player, double delta_time);
void	rotate_player_right(t_player *player, double delta_time);

#endif
