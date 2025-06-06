/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:56:03 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 13:08:38 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static t_point	scale_position(t_fpoint position);

t_corners	find_corners(t_size map_size, t_fpoint player_position);

void	draw_miniplayer(t_canvas *canvas, t_point start_point, t_player *player, t_size map_size)
{
	t_size	size;
	t_point	position;

	size = (t_size){MINIMAP_PLAYER_SIZE, MINIMAP_PLAYER_SIZE};
	position = scale_position(player->position);

	position.x -= size.width / 2;
	position.y -= size.height / 2;

	t_corners corners;
	corners = find_corners(map_size, player->position);
	t_point top_left;
	top_left.x = corners.top_left.x * MINIMAP_CELL_SIZE;
	top_left.y = corners.top_left.y * MINIMAP_CELL_SIZE;

	t_point minimap_pos;

	minimap_pos.x = start_point.x + position.x - top_left.x;
	minimap_pos.y = start_point.y + position.y - top_left.y;

	draw_rectangle(canvas, minimap_pos, size, PLAYER_COLOR);
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


void	draw_player(t_canvas *canvas, t_player *player)
{
	t_size	size;
	t_point	position;

	size = (t_size){MINIMAP_PLAYER_SIZE, MINIMAP_PLAYER_SIZE};
	position = scale_position(player->position);

	position.x -= size.width / 2;
	position.y -= size.height / 2;

	draw_rectangle(canvas, position, size, PLAYER_COLOR);
}


void	draw_rays(t_canvas *canvas, t_camera *camera)
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

static t_point	scale_position(t_fpoint position)
{
	t_point	scaled_position;

	scaled_position.x = position.x * MINIMAP_CELL_SIZE / CELL_SIZE;
	scaled_position.y = position.y * MINIMAP_CELL_SIZE / CELL_SIZE;
	return (scaled_position);
}

/*
      mini_pos           pos
------------------ =  ----------
   MINI_CELL_SIZE      CELL_SIZE
*/
