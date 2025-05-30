/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:22:08 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/30 19:02:12 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	fix_fish_eye_effect(t_ray *ray, double camera_angle);

void	draw_scene(t_canvas *canvas, t_camera *camera, t_textures *textures)
{
	draw_surface(canvas, textures->ceiling);
	draw_surface(canvas, textures->floor);
	draw_walls(canvas, camera, textures);
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

static void	fix_fish_eye_effect(t_ray *ray, double camera_angle)
{
	double	correction_angle;

	correction_angle = camera_angle - ray->angle;
	normalize_angle(&correction_angle);
	ray->length = ray->length * cos(correction_angle);
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
void	draw_textured_wall_slice(
	t_canvas *canvas,
	mlx_texture_t *texture,
	t_ray *ray,
	int x,
	int line_offset,
	int line_height,
	int line_width
);

void	draw_walls(t_canvas *canvas, t_camera *camera, t_textures *textures)
{
	t_ray	*ray;
	int		line_height;
	int		line_width;
	int		line_offset;

	line_width = 20;
	(void)textures;
	const int constant = CELL_SIZE * WINDOW_HEIGHT;
	for (int i = 0; i < camera->rays_count; i++)
	{
		ray = &camera->rays[i];
		fix_fish_eye_effect(ray, camera->angle);
		
		line_height = constant / ray->length;

		if (line_height > WINDOW_HEIGHT)
			line_height = WINDOW_HEIGHT;

		line_offset = WINDOW_HEIGHT / 2 - line_height / 2;

		int x = 600 + i * line_width;

		draw_textured_wall_slice(canvas, textures->north_wall->texture, ray, x, line_offset, line_height, line_width);
	}
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
//---------------------------VERSION 1------------------------------------
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// HERE YOU CAN SEE THE EFFECT WHERE WHEN YOU GET TOO CLOSE TO THE WALL
// IT'S BEING DISPLAYED WEIRDLY (WALL CORNER BECOMES FLAT)

/*
DATA NEEDED TO RUN AND SEE IT:

int digital_map[] =
	{
		1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,1,
		1,0,1,0,0,1,1,1,
		1,1,0,0,0,1,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,1,0,1,
		1,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1
	};

	//Player position
	// x: 261.294118, y: 315.295798
	
	//Camera angle
	// angle: 50.146168 (in degrees, not radians)
*/

void draw_textured_wall_slice(
	t_canvas *canvas,
	mlx_texture_t *texture,
	t_ray *ray,
	int x,
	int line_offset,
	int line_height,
	int line_width
)
{
	int		texture_x;
	int		texture_y;
	t_color	color;

	// Calculate which column of the texture to use
	if (ray->hit_type == VERTICAL_HIT)
		texture_x = ((int)ray->position.y % CELL_SIZE) * texture->width / CELL_SIZE;
	else
		texture_x = ((int)ray->position.x % CELL_SIZE) * texture->width / CELL_SIZE;

	// Draw the vertical line scaled to the screen
	for (int y = 0; y < line_height; y++)
	{
		texture_y = (y * texture->height) / line_height;
		color = get_texture_pixel(texture, texture_x, texture_y);

		int canvas_y = line_offset + y;
		//you have this loop, because you allowed to specify a width of a line
		//meaning that if you want to draw a line of width 8, using texture's pixel
		//you have to repeat it 8 times
		//so if you would draw lines of the width 1 you wouldn't need this loop
		for (int dx = 0; dx < line_width; dx++)
		{
			int canvas_x = x + dx;
			draw_pixel(canvas, canvas_x, canvas_y, color);
		}
	}
}

/*
This function is base on proportions:

Logic for the 'x' coordinate inside the texture image:

    x         texture_x
---------  =  ----------
CELL_SIZE   texture->width

so if we want to find 'texture_x', we have to do:
(x * texture->width) / CELL_SIZE;

where:
x = (int)ray->position.x % CELL_SIZE
or
x = (int)ray->position.y % CELL_SIZE

depending on whether it was a VERTICAL_HIT or HORIZONTAL_HIT

(and we want to modulo divide by CELL_SIZE
becacuse we want to know the 'x' coordinate within a cell,
and not within a screen)

so 'x' is a value from 0 to CELL_SIZE

/-------------------------------------------------------/
Same kind of logic for the 'y' coordinate:

    y         texture_y
---------  =  ----------
line_height   texture_height

so if we want to find 'texture_y', we have to do:
(y * texture->height) / line_height;

where 'y' is a value from 0 to line_height
*/

/*
ADDITIONAL EXAMPLE for the function above:

//Let's say ray.position.x = 45
//and let's say our texture is 120 pixels wide
//and let's say our CELL_SIZE is 64
//texture_x = 45 * 120 / 64 ≈ 84
//This means: “If I'm 70% through the wall, pick the 70% column of the texture.”
//meaning that 45 / 64 = 84 / 120 = 70% (simple proportion)
*/
