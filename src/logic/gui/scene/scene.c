/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:22:08 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/05 14:53:14 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void			fix_fish_eye_effect(t_ray *ray, double camera_angle);
static t_texture	*choose_texture(t_textures *textures, t_ray *ray,
						t_map *map);
static t_texture	*choose_wall_texture(t_textures *textures, t_ray *ray);
static t_color		add_shadows(t_ray *ray, t_color color);
static void			draw_textured_wall_slice(t_canvas *canvas, t_ray *ray,
						t_texture *texture, int ray_index);

void	draw_scene(t_canvas *canvas, t_camera *camera, t_textures *textures,
	t_map *map)
{
	draw_surface(canvas, textures->ceiling);
	draw_surface(canvas, textures->floor);
	draw_walls(canvas, camera, textures, map);
}

void	draw_surface(t_canvas *canvas, t_surface *surface)
{
	t_point	position;
	t_size	size;

	position.x = GAME_SCREEN_X_POSITION;
	size.width = GAME_SCREEN_WIDTH;
	size.height = GAME_SCREEN_HEIGHT / 2;
	if (surface->type == CEILING)
	{
		position.y = GAME_SCREEN_Y_POSITION;
		draw_rectangle(canvas, position, size, surface->color);
	}
	else if (surface->type == FLOOR)
	{
		position.y = GAME_SCREEN_HEIGHT / 2;
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

void	draw_walls(t_canvas *canvas, t_camera *camera, t_textures *textures,
	t_map *map)
{
	t_ray		*ray;
	t_texture	*texture;

	for (int i = 0; i < camera->rays_count; i++)
	{
		ray = &camera->rays[i];
		fix_fish_eye_effect(ray, camera->angle);

		texture = choose_texture(textures, ray, map);
		draw_textured_wall_slice(canvas, ray, texture, i);
	}
}

static t_texture	*choose_texture(t_textures *textures, t_ray *ray,
	t_map *map)
{
	int	x;
	int	y;

	x = ray->position.x / CELL_SIZE;
	y = ray->position.y / CELL_SIZE;
	if (is_door(map, x, y))
		return (textures->door->texture);
	return (choose_wall_texture(textures, ray));
}

static t_texture	*choose_wall_texture(t_textures *textures, t_ray *ray)
{
	t_texture	*texture;

	if (ray->hit_type == HORIZONTAL_HIT && angle_looks_up(ray->angle))
		texture = textures->south_wall->texture;
	else if (ray->hit_type == HORIZONTAL_HIT && angle_looks_down(ray->angle))
		texture = textures->north_wall->texture;
	else if (ray->hit_type == VERTICAL_HIT && angle_looks_left(ray->angle))
		texture = textures->east_wall->texture;
	else if (ray->hit_type == VERTICAL_HIT && angle_looks_right(ray->angle))
		texture = textures->west_wall->texture;
	else
		texture = NULL;
	return (texture);
}

static void draw_textured_wall_slice(t_canvas *canvas, t_ray *ray,
	t_texture *texture, int ray_index)
{
	double	texture_step;
	int		texture_x;
	double	texture_y;
	t_color	color;

	//-------------------------------
	int		line_height;
	int		line_width;
	int		line_offset;

	line_width = GAME_SCREEN_WIDTH / RAYS_COUNT;

	const int constant = CELL_SIZE * GAME_SCREEN_HEIGHT;
	line_height = constant / ray->length;

	int original_line_height = line_height;
	if (line_height > GAME_SCREEN_HEIGHT)
		line_height = GAME_SCREEN_HEIGHT;

	line_offset = GAME_SCREEN_Y_POSITION + GAME_SCREEN_HEIGHT / 2 - line_height / 2;

	int x = GAME_SCREEN_X_POSITION + ray_index * line_width;
	//-----------------------------------


	// Determine the texture column (X-axis)
	if (ray->hit_type == VERTICAL_HIT)
	{
		texture_x = ((int)ray->position.y % CELL_SIZE) * texture->width / CELL_SIZE;
		if (angle_looks_left(ray->angle))
			texture_x = (texture->width - 1) - texture_x;
	}
	else
	{
		texture_x = ((int)ray->position.x % CELL_SIZE) * texture->width / CELL_SIZE;
		if (angle_looks_down(ray->angle))
			texture_x = (texture->width - 1) - texture_x;
	}

	// Compute texture_step: how much to increment per screen pixel
	texture_step = (double)texture->height / original_line_height;

	// Determine where to start sampling the texture
	// If the line is taller than the screen, skip the top part of the texture
	int skip_top = 0;
	if (original_line_height > GAME_SCREEN_HEIGHT)
		skip_top = (original_line_height - GAME_SCREEN_HEIGHT) / 2;

	texture_y = skip_top * texture_step;
	for (int y = 0; y < line_height; y++)
	{
		// int tex_y = (int)texture_y;
		// if (tex_y >= (int)texture->height)
		// 	tex_y = texture->height - 1;

		color = get_texture_pixel(texture, texture_x, texture_y);

		color = add_shadows(ray, color);

		int canvas_y = line_offset + y;
		for (int dx = 0; dx < line_width; dx++)
		{
			int canvas_x = x + dx;
			draw_pixel(canvas, canvas_x, canvas_y, color);
		}

		texture_y += texture_step;
	}
}

/*
This function is based on proportions:

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

static t_color	add_shadows(t_ray *ray, t_color color)
{
	// Darken if it's a HORIZONTAL hit
	if (ray->hit_type == HORIZONTAL_HIT)
		color = darken_color(color, 0.7); // 70% brightness
		
	// Distance-based shading (more realistic)
	double max_visible = 800.0;
	double brightness = 1.0 - ray->length / max_visible;
	if (brightness < 0.3)
		brightness = 0.3; // Never completely black
		
	color = darken_color(color, brightness);
	return (color);
}
