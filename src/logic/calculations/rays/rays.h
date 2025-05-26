/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:28:54 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/26 16:42:28 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "map.h"
# include "player.h"
# include "ray.h"
# include "geometry.h"
# include "settings.h"

void		populate_rays(t_map *map, t_player *player);
void		find_ray_hit(t_map *map, t_player *player, t_ray *ray);
t_fpoint	find_horizontal_hit(t_map *map, t_player *player, double ray_angle);
t_fpoint	find_vertical_hit(t_map *map, t_player *player, double ray_angle);
t_fpoint	cast_ray(t_map *map, t_ray *ray, double x_offset, double y_offset);

#endif
