/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:28:54 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/23 16:57:19 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "map.h"
# include "player.h"
# include "ray.h"
# include "geometry.h"

# define GRID_WIDTH 8
# define GRID_HEIGHT 8
# define CELL_SIZE 64

t_fpoint	cast_ray(t_map *map, t_ray *ray);
t_fpoint	find_horizontal_hit(t_map *map, t_player *player, double ray_angle);
t_fpoint	find_vertical_hit(t_map *map, t_player *player, double ray_angle);
t_fpoint	find_ray_hit(t_map *map, t_player *player, double ray_angle);

#endif
