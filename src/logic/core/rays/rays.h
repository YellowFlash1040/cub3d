/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:28:54 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/07 20:48:10 by akovtune         ###   ########.fr       */
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

double		get_ray_angle_tan(double ray_angle);
double		get_ray_angle_cotan(double ray_angle);

void		calculate_first_intersection_up(t_player *player,
				t_ray *ray, double angle_cotan);
void		calculate_first_intersection_down(t_player *player,
				t_ray *ray, double angle_cotan);
void		calculate_first_intersection_right(t_player *player,
				t_ray *ray, double angle_tan);
void		calculate_first_intersection_left(t_player *player,
				t_ray *ray, double angle_tan);

t_fpoint	cast_ray(t_map *map, t_ray *ray, double x_offset, double y_offset);

#endif
