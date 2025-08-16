/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:30 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/02 15:10:05 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
# define MOVEMENTS_H

# include "settings.h"
# include "geometry.h"
# include "player.h"
# include "map.h"

void	move_player_forward(t_map *map, t_player *player, double delta_time);
void	move_player_backward(t_map *map, t_player *player, double delta_time);
void	move_player_left(t_map *map, t_player *player, double delta_time);
void	move_player_right(t_map *map, t_player *player, double delta_time);
void	move_if_possible(t_map *map, t_player *player, t_fpoint new_position);

#endif
