/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:02:04 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 16:41:16 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clipped_minimap.h"

void	draw_clipped_player(t_canvas *canvas, t_point start_point,
	t_player *player, t_size map_size)
{
	t_map_point	map_corner;
	t_point		top_left;
	t_point		position;
	t_point		clipped_map_pos;
	t_size		size;

	map_corner = find_corners(map_size, player->position).top_left;
	top_left.x = map_corner.x * MINIMAP_CELL_SIZE;
	top_left.y = map_corner.y * MINIMAP_CELL_SIZE;
	position = scale_position(player->position);
	clipped_map_pos.x = position.x - top_left.x;
	clipped_map_pos.y = position.y - top_left.y;
	apply_offset(&clipped_map_pos, start_point);
	size = (t_size){MINIMAP_PLAYER_SIZE, MINIMAP_PLAYER_SIZE};
	clipped_map_pos.x -= size.width / 2;
	clipped_map_pos.y -= size.height / 2;
	draw_rectangle(canvas, clipped_map_pos, size, PLAYER_COLOR);
}

void	draw_minirays(t_canvas *canvas, t_camera *camera)
{
	t_fpoint	hit;
	t_point		camera_pos;
	t_point		wall;
	int			i;

	camera_pos = scale_position(camera->position);
	i = -1;
	while (++i < camera->rays_count)
	{
		hit = camera->rays[i].position;
		wall = scale_position(hit);
		draw_line(canvas, camera_pos, wall, RAY_COLOR);
	}
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
