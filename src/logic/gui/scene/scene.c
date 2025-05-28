/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:22:08 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/28 18:24:57 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	draw_scene(t_canvas *canvas, t_camera *camera, t_settings *settings)
{
	t_ray	*ray;
	int		line_height;
	int		line_width;
	int		line_offset;
	double	correction_angle;

	draw_surface(canvas, settings->ceiling);
	draw_surface(canvas, settings->floor);

	line_width = 20;
	for (int i = 0; i < camera->rays_count; i++)
	{
		ray = &camera->rays[i];
		
		//Fix for the "fish eye" effect
		correction_angle = camera->angle - ray->angle;
		normalize_angle(&correction_angle);
		ray->length = ray->length * cos(correction_angle);
		
		//What I understand for now is:
		//1) the bigger the length of the ray,
		//the smalller the line_height will be, making depth effect
		//2) you want to have a constant against which you can compare the ray->length
		//in order to proportionally scale lines
		//meaning that if you have ray->length of 10
		//the line_height will be = constant / 10;
		//and if you have a ray->length of 20
		//the line height will be = constant / 20;
		//which is twice smaller than constant / 10
		//meaning the line_height has to be twice smaller.
		//But where does this CELL_SIZE * WINDOW_HEIGHT come from - no idea
		line_height = CELL_SIZE * WINDOW_HEIGHT / ray->length;

		//make sure that if object goes outside of the screen to not draw it fully,
		//since you will not see it anyway
		if (line_height > WINDOW_HEIGHT)
			line_height = WINDOW_HEIGHT;

		//Defines where user's game screen starts
		int x = 600 + i * line_width;

		//not sure yet, but it seems like you can control camera pitch with it
		//for now it puts all of the lines in the middle of the screen
		line_offset = WINDOW_HEIGHT / 2 - line_height / 2;

		//creates the shadow effect
		if (ray->hit_type == VERTICAL_HIT)
			draw_line(canvas, (t_point){x, line_offset}, (t_point){x, line_offset + line_height}, line_width, (t_color)0xff0000ff);
		else
			draw_line(canvas, (t_point){x, line_offset}, (t_point){x, line_offset + line_height}, line_width, (t_color)0xcc0000ff);
	}
}

void	draw_surface(t_canvas *canvas, t_surface *surface)
{
	t_point	position;
	t_size	size;

	size.width = 1200;
	size.height = WINDOW_HEIGHT / 2;
	position.x = 590;
	if (surface->type == CEILING)
	{
		position.y = 0;
		draw_rectangle(canvas, position, size, surface->color);
	}
	else if (surface->type == FLOOR)
	{
		position.y = WINDOW_HEIGHT / 2;
		draw_rectangle(canvas, position, size, surface->color);
	}
}
