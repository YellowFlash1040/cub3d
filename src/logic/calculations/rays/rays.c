/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:28:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/21 13:37:24 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_fpoint	find_horizontal_hit(t_player *player, t_map *map)
{
	int			rays_count;
	double		ray_angle;
	int			depth_of_field; // number of steps taken in a ray before it hits a wall or gives up
	t_fpoint	ray_position;
	double		x_offset;
	double		y_offset;

	rays_count = 1;

	ray_position.x = player->position.x;
	ray_position.y = player->position.y;
	ray_angle = player->angle;
	for (int i = 0; i < rays_count; i++)
	{
		depth_of_field = 0;

		if (fabs(tan(ray_angle)) < EPSILON) //if tan(angle) is very close to 0
			ray_angle += 0.0001; // nudge (shift) the angle a bit

		double angleCotan = -1 / tan(ray_angle); // so that it will not break here
		//because of the possible division by zero or by a really small number
		
		//figure out in which direction our ray is looking
		if (fabs(ray_angle) < EPSILON || fabs(M_PI - ray_angle) < EPSILON) //looking straight to the left or right
		{
			//then no horizontal intersections are possible
			ray_position.x = player->position.x;
			ray_position.y = player->position.y;
			//so we can end our searches
			depth_of_field = GRID_WIDTH;
		}
		else if (ray_angle < M_PI) // looking up
		{
			//calculate what is the y coordinate of the start of my cell
			//and then go a bit beyond that edge to the top 
			//to find the cell I'll be intersecting with
			ray_position.y = (int)player->position.y / CELL_SIZE * CELL_SIZE - 0.0001;
			// the x coordinate of the ray collision is being found using a triangle formula:
			//                        length if the 
			ray_position.x = (ray_position.y - player->position.y) * angleCotan + player->position.x;
			y_offset = -CELL_SIZE;
			x_offset = y_offset * angleCotan;	
		}
		else if (ray_angle > M_PI) //looking down
		{
			ray_position.y = (int)player->position.y / CELL_SIZE * CELL_SIZE + CELL_SIZE;
			ray_position.x = (ray_position.y - player->position.y) * angleCotan + player->position.x;
			y_offset = CELL_SIZE;
			x_offset = y_offset * angleCotan;
		}
		//go in that direction and look for a hit
		int map_x, map_y, map_index;
		while (depth_of_field < GRID_WIDTH)
		{
			map_x = (int)ray_position.x / CELL_SIZE;
			// map_y = (int)ray_position.y / CELL_SIZE - 1;
			map_y = (int)ray_position.y / CELL_SIZE;
			map_index = (map_y * GRID_WIDTH) + map_x;
			if ((map_x >= 0 && map_x < GRID_WIDTH && map_y >= 0 && map_y < GRID_HEIGHT) && map->cells[map_y][map_x] == '1')
				break ;
			else
			{
				ray_position.x += x_offset;
				ray_position.y += y_offset;
				depth_of_field += 1;
			}
		}
	}
	return (ray_position);
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

t_fpoint	find_vertical_hit(t_player *player, t_map *map)
{
	int			rays_count;
	double		ray_angle;
	int			depth_of_field; // number of steps taken in a ray before it hits a wall or gives up
	t_fpoint	ray_position;
	double		x_offset;
	double		y_offset;

	rays_count = 1;

	ray_position.x = player->position.x;
	ray_position.y = player->position.y;
	ray_angle = player->angle;
	for (int i = 0; i < rays_count; i++)
	{
		depth_of_field = 0;

		
		if (fabs(tan(ray_angle)) < EPSILON)
		// if (fabs(M_PI_2 - ray_angle) < EPSILON || fabs(M_3_PI_2 - ray_angle) < EPSILON)
			ray_angle += 0.0001;

		double angleTan = -tan(ray_angle);
		
		if (fabs(M_PI_2 - ray_angle) < EPSILON || fabs(M_3_PI_2 - ray_angle) < EPSILON) //looking straight to the top or to the bottom
		{
			ray_position.x = player->position.x;
			ray_position.y = player->position.y;
			depth_of_field = GRID_HEIGHT;
		}
		else if (ray_angle < M_PI_2 || ray_angle > M_3_PI_2) // looking right
		{
			ray_position.x = (int)player->position.x / CELL_SIZE * CELL_SIZE + CELL_SIZE;
			ray_position.y = (ray_position.x - player->position.x) * angleTan + player->position.y;
			x_offset = CELL_SIZE;
			y_offset = x_offset * angleTan;
		}
		else if (ray_angle > M_PI_2 && ray_angle < M_3_PI_2) // looking left
		{
			ray_position.x = (int)player->position.x / CELL_SIZE * CELL_SIZE - 0.0001;
			ray_position.y = (ray_position.x - player->position.x) * angleTan + player->position.y;
			x_offset = -CELL_SIZE;
			y_offset = x_offset * angleTan;
		}
		//go in that direction and look for a hit
		int map_x, map_y, map_index;
		while (depth_of_field < GRID_WIDTH)
		{
			map_x = (int)ray_position.x / CELL_SIZE;
			// map_y = (int)ray_position.y / CELL_SIZE - 1;
			map_y = (int)ray_position.y / CELL_SIZE;
			map_index = (map_y * GRID_WIDTH) + map_x;
			if ((map_x >= 0 && map_x < GRID_WIDTH && map_y >= 0 && map_y < GRID_HEIGHT) && map->cells[map_y][map_x] == '1')
				break ;
			else
			{
				ray_position.x += x_offset;
				ray_position.y += y_offset;
				depth_of_field += 1;
			}
		}
	}
	return (ray_position);
}

// Pythagorean theorem
// c² = a² + b²
// we need to find 'c'
// so we need to find a square root from a² + b²
double find_distance(t_fpoint a, t_fpoint b)
{
	double	dx; // Difference in x-coordinates
    double	dy; // Difference in y-coordinates
	double	distance;

    dx = b.x - a.x;
    dy = b.y - a.y;
    distance = sqrt(dx * dx + dy * dy);

	return (distance);
}

t_fpoint	find_ray_hit(t_player *player, t_map *map)
{
	t_fpoint	horizontal_hit;
	t_fpoint	vertical_hit;
	double		horizontal_hit_distance;
	double		vertical_hit_distance;

	horizontal_hit = find_horizontal_hit(player, map);
	vertical_hit = find_vertical_hit(player, map);

	horizontal_hit_distance = find_distance(player->position, horizontal_hit);
	vertical_hit_distance = find_distance(player->position, vertical_hit);

	if (horizontal_hit_distance <= vertical_hit_distance)
		return (horizontal_hit);
	return (vertical_hit);
}
