/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:00:53 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/07 19:30:32 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall_drawing.h"

static void			fix_fish_eye_effect(t_ray *ray, double camera_angle);
static t_texture	*choose_texture(t_textures *textures, t_ray *ray,
						t_map *map);
static t_texture	*choose_wall_texture(t_textures *textures, t_ray *ray);

void	draw_walls(t_canvas *canvas, t_camera *camera, t_textures *textures,
	t_map *map)
{
	t_ray		*ray;
	t_texture	*texture;
	int			i;

	i = 0;
	while (i < camera->rays_count)
	{
		ray = &camera->rays[i];
		fix_fish_eye_effect(ray, camera->angle);
		texture = choose_texture(textures, ray, map);
		draw_textured_wall_slice(canvas, ray, texture, i);
		i++;
	}
}

static void	fix_fish_eye_effect(t_ray *ray, double camera_angle)
{
	double	correction_angle;

	correction_angle = camera_angle - ray->angle;
	normalize_angle(&correction_angle);
	ray->length = ray->length * cos(correction_angle);
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
