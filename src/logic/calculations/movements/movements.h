/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:30 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/28 14:51:01 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
# define MOVEMENTS_H

# include "settings.h"
# include "geometry.h"
# include "player.h"
# include "map.h"

void	move_player_forward(t_map *map, t_player *player);
void	move_player_back(t_map *map, t_player *player);
void	rotate_player_left(t_player *player);
void	rotate_player_right(t_player *player);

#endif
