/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:22:08 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/26 17:17:55 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	draw_scene(t_canvas *canvas, t_camera *camera)
{
	t_ray	*ray;
	int		line_height;
	int		line_width;
	int		line_offset;
	double	correction_angle;

	(void)canvas;
	line_width = 20;
	for (int i = 0; i < camera->rays_count; i++)
	{
		ray = &camera->rays[i];
		
		correction_angle = camera->angle - ray->angle;
		normalize_angle(&correction_angle);
		ray->length = ray->length * cos(correction_angle);
		
		line_height = CELL_SIZE * WINDOW_HEIGHT / ray->length;
		if (line_height > WINDOW_HEIGHT)
			line_height = WINDOW_HEIGHT;
		int x = 600 + i * line_width;
		line_offset = WINDOW_HEIGHT / 2 - line_height / 2;
		if (ray->hit_type == VERTICAL_HIT)
			draw_line(canvas, (t_point){x, line_offset}, (t_point){x, line_offset + line_height}, line_width, (t_color)0xff0000ff);
		else
			draw_line(canvas, (t_point){x, line_offset}, (t_point){x, line_offset + line_height}, line_width, (t_color)0xcc0000ff);
	}
}


/*
void	draw_scene(t_canvas *canvas, t_camera *camera)
{
	t_ray	ray;
	double	line_height;

	(void)canvas;
	for (int i = 0; i < camera->rays_count; i++)
	{
		ray = camera->rays[i];
		line_height = CELL_SIZE * WINDOW_HEIGHT / ray.length;
		if (line_height > WINDOW_HEIGHT)
			line_height = WINDOW_HEIGHT;
		int x = 800 + CELL_SIZE * i;
		draw_line(canvas, (t_point){x, 0}, (t_point){x, line_height}, 8, (t_color)0xffff00ff);
	}
}
*/