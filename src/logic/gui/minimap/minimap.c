/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:11:37 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/26 17:22:21 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static void	draw_map(t_canvas *canvas, t_map* map);
static void	draw_player(t_canvas *canvas, t_player *player);
static void	draw_rays(t_canvas *canvas, t_camera *camera);

void	draw_minimap(t_canvas *canvas, t_map *map, t_player *player)
{
	draw_map(canvas, map);
	draw_player(canvas, player);
}

static void draw_map(t_canvas *canvas, t_map* map)
{
	int	x;
	int	y;
	
	int cell_size = 64;
	t_color colorWhite = get_color(255, 255, 255, 255);
	t_color colorRed = get_color(255, 0, 0, 255);
	t_color colorGreen = get_color(0, 255, 0, 255);
	t_color colorBlack = get_color(0, 0, 0, 255);
	t_color color;

	(void)colorWhite;
	(void)colorRed;
	(void)colorGreen;
	(void)colorBlack;
	(void)color;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->cells[y][x] == '0')
				color = colorBlack;
			else if (map->cells[y][x] == '1')
				color = colorWhite;
			else
				color = colorGreen;
			draw_rectangle(canvas,
				(t_point){x * cell_size, y * cell_size},
				(t_size){cell_size - 1, cell_size - 1},
				color);
		}
	}
}

static void	draw_player(t_canvas *canvas, t_player *player)
{
	t_size	size;
	t_point	position;

	size = (t_size){10, 10};
	position.x = player->position.x - size.width / 2;
	position.y = player->position.y - size.height / 2;
	draw_rectangle(canvas, position, size, (t_color)0xffff00ff);
	draw_rays(canvas, player->camera);
}

static void	draw_rays(t_canvas *canvas, t_camera *camera)
{
	t_fpoint	hit;
	t_point		camera_pos;
	t_point		wall;

	camera_pos = (t_point){(int)round(camera->position.x), (int)round(camera->position.y)};
	for (int i = 0; i < camera->rays_count; i++)
	{
		hit = camera->rays[i].position;
		wall = (t_point){(int)round(hit.x), (int)round(hit.y)};
		draw_line(canvas, camera_pos, wall, 1, 0x00ffffff);
	}
}
