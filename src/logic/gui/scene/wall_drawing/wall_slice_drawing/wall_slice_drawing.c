/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_slice_drawing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:15:07 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/07 19:32:51 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall_slice_drawing.h"

static int			determine_texture_column(t_ray *ray, t_texture *texture);
static double		determine_texture_row(t_ray *ray, t_texture *texture);
static t_line_info	get_line_info(t_ray *ray, int ray_index);
static void			render_texture_column(t_canvas *canvas, t_ray *ray,
						t_line_info *line, t_texture_info *texture);

void	draw_textured_wall_slice(t_canvas *canvas, t_ray *ray,
	t_texture *texture, int ray_index)
{
	t_line_info		line;
	t_texture_info	texture_info;

	line = get_line_info(ray, ray_index);
	texture_info.texture = texture;
	texture_info.x = determine_texture_column(ray, texture);
	texture_info.y = determine_texture_row(ray, texture);
	texture_info.step = (double)texture->height / line.original_height;
	render_texture_column(canvas, ray, &line, &texture_info);
}

static int	determine_texture_column(t_ray *ray, t_texture *texture)
{
	int	texture_x;

	if (ray->hit_type == VERTICAL_HIT)
	{
		texture_x = ((int)ray->position.y % CELL_SIZE)
			* texture->width / CELL_SIZE;
		if (angle_looks_left(ray->angle))
			texture_x = (texture->width - 1) - texture_x;
	}
	else
	{
		texture_x = ((int)ray->position.x % CELL_SIZE)
			* texture->width / CELL_SIZE;
		if (angle_looks_down(ray->angle))
			texture_x = (texture->width - 1) - texture_x;
	}
	return (texture_x);
}

static double	determine_texture_row(t_ray *ray, t_texture *texture)
{
	const int	constant = CELL_SIZE * GAME_SCREEN_HEIGHT;
	int			line_height;
	double		texture_step;
	double		texture_y;

	line_height = constant / ray->length;
	texture_step = (double)texture->height / line_height;
	texture_y = 0;
	if (line_height > GAME_SCREEN_HEIGHT)
		texture_y = (line_height - GAME_SCREEN_HEIGHT) / 2.0 * texture_step;
	return (texture_y);
}

/*
This logic is based on proportions:

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

static t_line_info	get_line_info(t_ray *ray, int ray_index)
{
	t_line_info	line;
	const int	constant = CELL_SIZE * GAME_SCREEN_HEIGHT;

	line.width = GAME_SCREEN_WIDTH / RAYS_COUNT;
	line.height = constant / ray->length;
	line.original_height = line.height;
	if (line.height > GAME_SCREEN_HEIGHT)
		line.height = GAME_SCREEN_HEIGHT;
	line.canvas_pos.y = GAME_SCREEN_Y_POSITION
		+ GAME_SCREEN_HEIGHT / 2 - line.height / 2;
	line.canvas_pos.x = GAME_SCREEN_X_POSITION + ray_index * line.width;
	return (line);
}

static void	render_texture_column(t_canvas *canvas, t_ray *ray,
	t_line_info *line, t_texture_info *texture)
{
	int				i;
	t_color			color;

	i = 0;
	while (i < line->height)
	{
		color = get_texture_pixel(texture->texture, texture->x, texture->y);
		color = add_shadows(ray, color);
		draw_horizontal_line(canvas, line->canvas_pos, line->width, color);
		line->canvas_pos.y++;
		texture->y += texture->step;
		i++;
	}
}
