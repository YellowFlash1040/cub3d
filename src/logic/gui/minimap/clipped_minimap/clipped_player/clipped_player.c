/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipped_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:02:04 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/08 15:53:38 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clipped_minimap.h"

static t_point	get_clipped_map_position(t_point start_point,
					t_fpoint world_pos, t_size map_size);
void			draw_direction_ray(t_canvas *canvas, t_point player_pos,
					double angle);

void	draw_clipped_player(t_canvas *canvas, t_point start_point,
	t_player *player, t_size map_size)
{
	t_point		clipped_map_pos;
	t_size		size;

	clipped_map_pos = get_clipped_map_position(start_point,
			player->position, map_size);
	size = (t_size){MINIMAP_PLAYER_SIZE, MINIMAP_PLAYER_SIZE};
	clipped_map_pos.x -= size.width / 2;
	clipped_map_pos.y -= size.height / 2;
	draw_rectangle(canvas, clipped_map_pos, size, PLAYER_COLOR);
	draw_direction_ray(canvas, clipped_map_pos, player->camera->angle);
}

void	draw_direction_ray(t_canvas *canvas, t_point player_pos, double angle)
{
	t_vector	step;
	t_point		end_point;

	step = get_unit_vector(angle);
	if (angle_looks_right(angle))
		player_pos.x += MINIMAP_PLAYER_SIZE / 2;
	if (angle_looks_down(angle))
		player_pos.y += MINIMAP_PLAYER_SIZE / 2;
	end_point.x = player_pos.x + step.x * MINIMAP_PLAYER_SIZE * 1.5;
	end_point.y = player_pos.y + step.y * MINIMAP_PLAYER_SIZE * 1.5;
	draw_line(canvas, player_pos, end_point, PLAYER_COLOR);
}

void	draw_clipped_rays(t_canvas *canvas, t_point start_point,
	t_camera *camera, t_size map_size)
{
	t_fpoint	hit;
	t_point		camera_pos;
	t_point		wall;
	int			i;

	camera_pos = get_clipped_map_position(start_point,
			camera->position, map_size);
	i = -1;
	while (++i < camera->rays_count)
	{
		hit = camera->rays[i].position;
		wall = get_clipped_map_position(start_point, hit, map_size);
		draw_line(canvas, camera_pos, wall, RAY_COLOR);
	}
}

static t_point	get_clipped_map_position(t_point start_point,
	t_fpoint world_pos, t_size map_size)
{
	t_map_point	map_corner;
	t_point		position;
	t_point		top_left;
	t_point		clipped_map_pos;

	map_corner = find_corners(map_size, world_pos).top_left;
	top_left.x = map_corner.x * MINIMAP_CELL_SIZE;
	top_left.y = map_corner.y * MINIMAP_CELL_SIZE;
	position = scale_position(world_pos);
	clipped_map_pos.x = position.x - top_left.x;
	clipped_map_pos.y = position.y - top_left.y;
	apply_offset(&clipped_map_pos, start_point);
	return (clipped_map_pos);
}

/*
void	draw_clipped_player(t_canvas *canvas, t_point start_point,
	t_player *player, t_size map_size)
{
	t_map_point	map_corner;
	t_point		top_left;
	t_point		position;
	t_size		size;
	t_point		minimap_pos;

	// find map's top left cell inside "data map"
	// that is visible inside "clipped minimap"
	map_corner = find_corners(map_size, player->position).top_left;
	// find it's coordinates inside the minimap world
	top_left.x = map_corner.x * MINIMAP_CELL_SIZE;
	top_left.y = map_corner.y * MINIMAP_CELL_SIZE;

	//find player position inside the minimap world
	position = scale_position(player->position);

	//find difference in coordinates between
	//top left cell and player
	minimap_pos.x = position.x - top_left.x;
	minimap_pos.y = position.y - top_left.y;

	//apply offset
	//so that this difference will be from 
	//the point where you have to draw the clipped minimap
	apply_offset(&minimap_pos, start_point);

	size = (t_size){MINIMAP_PLAYER_SIZE, MINIMAP_PLAYER_SIZE};
	//center rectangle relatively to it's position
	minimap_pos.x -= size.width / 2;
	minimap_pos.y -= size.height / 2;
	//draw
	draw_rectangle(canvas, minimap_pos, size, PLAYER_COLOR);
}
*/
