/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:28:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/04 16:42:12 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

void	populate_rays(t_map *map, t_player *player)
{
	t_camera	*camera;
	t_ray		*ray;
	double		ray_angle;
	double		angle_step;

	camera = player->camera;
	angle_step = player->camera->fov / player->camera->rays_count;
	ray_angle = player->camera->angle + player->camera->fov / 2;
	normalize_angle(&ray_angle);
	for (int i = 0; i < player->camera->rays_count; i++)
	{
		ray = &camera->rays[i];
		ray->angle = ray_angle;
		find_ray_hit(map, player, ray);
		ray->length = find_distance(player->position, ray->position);
		ray_angle -= angle_step;
		normalize_angle(&ray_angle);
	}
}

void	find_ray_hit(t_map *map, t_player *player, t_ray *ray)
{
	t_fpoint	horizontal_hit;
	t_fpoint	vertical_hit;
	double		horizontal_hit_distance;
	double		vertical_hit_distance;

	horizontal_hit = find_horizontal_hit(map, player, ray->angle);
	vertical_hit = find_vertical_hit(map, player, ray->angle);
	horizontal_hit_distance = find_distance(player->position, horizontal_hit);
	vertical_hit_distance = find_distance(player->position, vertical_hit);
	if (horizontal_hit_distance <= vertical_hit_distance)
	{
		ray->hit_type = HORIZONTAL_HIT;
		ray->position = horizontal_hit;
	}
	else
	{
		ray->hit_type = VERTICAL_HIT;
		ray->position = vertical_hit;
	}
}

t_fpoint	find_horizontal_hit(t_map *map, t_player *player, double ray_angle)
{
	t_ray		ray;
	double		angle_cotan;
	double		x_offset;
	double		y_offset;

	x_offset = 0;
	y_offset = 0;
	ray.position = player->position;
	if (is_almost_zero(tan(ray_angle))) // if tan(angle) is very close to 0
		ray_angle += 0.0001; // nudge (shift) the angle a bit
	angle_cotan = -1 / tan(ray_angle);
	// so that it will not break here
	// because of the possible division by zero or by a really small number
	// figure out in which direction our ray is looking
	if (is_horizontal_angle(ray_angle)) // looking straight to the left or right
		// then no horizontal intersections are possible
		return (ray.position);
	else if (angle_looks_up(ray_angle)) // looking up
	{
		// calculate what is the y coordinate of the start of my cell
		// and then go a bit beyond that edge to the top
		// to find the cell I'll be intersecting with
		ray.position.y = (int)player->position.y / CELL_SIZE * CELL_SIZE
			- 0.0001;
		// the x coordinate of the ray collision is being found using a triangle formula:
		//                        length if the
		ray.position.x = (ray.position.y - player->position.y) * angle_cotan
			+ player->position.x;
		y_offset = -CELL_SIZE;
		x_offset = y_offset * angle_cotan;
	}
	else if (angle_looks_down(ray_angle)) // looking down
	{
		ray.position.y = (int)player->position.y / CELL_SIZE * CELL_SIZE
			+ CELL_SIZE;
		ray.position.x = (ray.position.y - player->position.y) * angle_cotan
			+ player->position.x;
		y_offset = CELL_SIZE;
		x_offset = y_offset * angle_cotan;
	}
	// go in that direction and look for a hit
	ray.position = cast_ray(map, &ray, x_offset, y_offset);
	return (ray.position);
}

/*
if you want to find a horizontal collision that is above the player
you can either do:

else if (ray_angle < M_PI) // looking up
{
  ray_position.y = (int)player->position.y / CELL_SIZE * CELL_SIZE - 0.0001;
  ...
}

or

while (depth_of_field < GRID_WIDTH)
{
	map_y = (int)ray_position.y / CELL_SIZE - 1;
	...
}

but in the second case (the one with the while loop)
you need to be sure that the player's y position
can never be less than CELL_SIZE (64 in my case)

otherwise you will end up with:
map_y = -1
and Segfault
*/

t_fpoint	find_vertical_hit(t_map *map, t_player *player, double ray_angle)
{
	t_ray		ray;
	double		angle_tan;
	double		x_offset;
	double		y_offset;

	x_offset = 0;
	y_offset = 0;
	ray.position = player->position;
	if (is_almost_zero(tan(ray_angle)))
		ray_angle += 0.0001;
	angle_tan = -tan(ray_angle);
	if (is_vertical_angle(ray_angle)) // looking straight to the top or to the bottom
		return (ray.position);
	else if (angle_looks_right(ray_angle)) // looking right
	{
		ray.position.x = (int)player->position.x / CELL_SIZE * CELL_SIZE
			+ CELL_SIZE;
		ray.position.y = (ray.position.x - player->position.x) * angle_tan
			+ player->position.y;
		x_offset = CELL_SIZE;
		y_offset = x_offset * angle_tan;
	}
	else if (angle_looks_left(ray_angle)) // looking left
	{
		ray.position.x = (int)player->position.x / CELL_SIZE * CELL_SIZE
			- 0.0001;
		ray.position.y = (ray.position.x - player->position.x) * angle_tan
			+ player->position.y;
		x_offset = -CELL_SIZE;
		y_offset = x_offset * angle_tan;
	}
	// go in that direction and look for a hit
	ray.position = cast_ray(map, &ray, x_offset, y_offset);
	return (ray.position);
}

t_fpoint	cast_ray(t_map *map, t_ray *ray, double x_offset, double y_offset)
{
	int	depth_of_field;
	int	map_x;
	int	map_y;
	int	max_depth;

	depth_of_field = 0;
	max_depth = map->height;
	if (map->width > map->height)
		max_depth = map->width;
	while (depth_of_field < max_depth)
	{
		map_x = (int)ray->position.x / CELL_SIZE;
		map_y = (int)ray->position.y / CELL_SIZE;
		if (map_x < 0 || map_x >= map->width
			|| map_y < 0 || map_y >= map->height)
			break ;
		if (is_obstacle(map, map_x, map_y))
			break ;
		ray->position.x += x_offset;
		ray->position.y += y_offset;
		depth_of_field++;
	}
	return (ray->position);
}
