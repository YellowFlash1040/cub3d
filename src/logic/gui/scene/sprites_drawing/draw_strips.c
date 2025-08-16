/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_strips.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 12:31:38 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/21 12:40:50 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites_drawing.h"

static void	draw_strip(t_draw_sprite_data *d);

void	draw_strips(t_draw_sprite_data *d)
{
	int	i;

	i = -1;
	while (++i < d->total_strips)
	{
		d->ray_index = d->left_ray_index + i;
		if (d->depth < d->camera->rays[d->ray_index].length)
		{
			d->strip_left = d->draw_left + (d->strip_width * i);
			d->strip_right = d->draw_left + (d->strip_width * (i + 1));
			d->draw_point = (t_point){d->strip_left, d->draw_top};
			d->strip_size = (t_size){d->strip_right - d->strip_left,
				d->strip_height};
			d->sprite_position.x = d->strip_left
				- (d->screen_x - d->sprite_screen_width / 2);
			d->sprite_position.y = d->draw_top
				- (d->screen_y - d->sprite_screen_height / 2);
			draw_strip(d);
		}
	}
}

static void	draw_strip(t_draw_sprite_data *d)
{
	t_point	p;
	double	texture_x;
	double	texture_y;
	t_color	pixel;

	texture_y = d->sprite_position.y * d->texture_y_step;
	p.y = -1;
	while (++p.y < d->strip_size.height)
	{
		texture_x = d->sprite_position.x * d->texture_x_step;
		p.x = -1;
		while (++p.x < d->strip_size.width)
		{
			pixel = get_texture_pixel(d->texture, texture_x, texture_y);
			if (pixel != 0x000000)
				draw_pixel(d->canvas,
					d->draw_point.x + p.x, d->draw_point.y + p.y, pixel);
			texture_x += d->texture_x_step;
			if (texture_x >= d->texture->width)
				texture_x = d->texture->width - 1;
		}
		texture_y += d->texture_y_step;
		if (texture_y >= d->texture->height)
			texture_y = d->texture->height - 1;
	}
}

//one more helper which just didn't fit inside the helpers file
//because of the 5 functions limit

bool	behind_the_camera(t_draw_sprite_data *d)
{
	if (d->depth < 1)
		return (true);
	return (false);
}
