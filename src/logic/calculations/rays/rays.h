/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:28:54 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/21 13:42:15 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include <math.h>
# include "drawing.h"
# include "fpoint.h"
# include "player.h"
# include "map.h"
# include "constants.h"

# define GRID_WIDTH 8
# define GRID_HEIGHT 8
# define CELL_SIZE 64

t_fpoint	find_ray_hit(t_player *player, t_map *map);

t_fpoint	find_horizontal_hit(t_player *player, t_map *map);
t_fpoint	find_vertical_hit(t_player *player, t_map *map);

double		find_distance(t_fpoint a, t_fpoint b);

#endif
