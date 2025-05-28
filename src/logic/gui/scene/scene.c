/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:22:08 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/27 19:07:18 by akovtune         ###   ########.fr       */
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
		
		//fish eye effect fix
		correction_angle = camera->angle - ray->angle;
		normalize_angle(&correction_angle);
		ray->length = ray->length * cos(correction_angle);
		
		//no idea yet about what is the logic behind this calculation
		//the only thing that I understand for now is:
		//the bigger the length of the ray,
		//the smalller the line_height will be,
		//making depth effect
		line_height = CELL_SIZE * WINDOW_HEIGHT / ray->length;
		// line_height = 10 * WINDOW_HEIGHT / ray->length;

		//make sure that if object goes outside of the screen to not draw it fully,
		//since you will not see it anyway
		if (line_height > WINDOW_HEIGHT)
			line_height = WINDOW_HEIGHT;

		//define where users game screen starts
		int x = 600 + i * line_width;
		// int x = 300 + i * line_width;

		//not sure yet, but it seems like you can control camera pitch with it
		//for now it puts all of the lines in the middle of the screen
		line_offset = WINDOW_HEIGHT / 2 - line_height / 2;

		// line_offset = 0;
		// line_offset = WINDOW_HEIGHT - line_height;
		// line_offset = camera->lean - line_height / 2;
		line_offset = WINDOW_HEIGHT / 2 - line_height / 2 + camera->lean;

		//creates the shadow effect
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