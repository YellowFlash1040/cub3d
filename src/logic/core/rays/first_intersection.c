/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:27:06 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/07 20:37:02 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

void	calculate_first_intersection_up(t_player *player, t_ray *ray,
	double angle_cotan)
{
	ray->position.y = (int)player->position.y / CELL_SIZE * CELL_SIZE
		- 0.0001;
	ray->position.x = (ray->position.y - player->position.y) * angle_cotan
		+ player->position.x;
}

void	calculate_first_intersection_down(t_player *player, t_ray *ray,
	double angle_cotan)
{
	ray->position.y = (int)player->position.y / CELL_SIZE * CELL_SIZE
		+ CELL_SIZE;
	ray->position.x = (ray->position.y - player->position.y) * angle_cotan
		+ player->position.x;
}

void	calculate_first_intersection_right(t_player *player, t_ray *ray,
	double angle_tan)
{
	ray->position.x = (int)player->position.x / CELL_SIZE * CELL_SIZE
		+ CELL_SIZE;
	ray->position.y = (ray->position.x - player->position.x) * angle_tan
		+ player->position.y;
}

void	calculate_first_intersection_left(t_player *player, t_ray *ray,
	double angle_tan)
{
	ray->position.x = (int)player->position.x / CELL_SIZE * CELL_SIZE
		- 0.0001;
	ray->position.y = (ray->position.x - player->position.x) * angle_tan
		+ player->position.y;
}
