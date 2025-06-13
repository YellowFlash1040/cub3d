/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_loader.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:20:56 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 16:34:26 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation_loader.h"

static int	load_frames(t_sprite_sheet *sprite_sheet, t_animation *animation);
static void	copy_pixels(t_sprite_sheet *sprite_sheet,
				int sprite_sheet_x, t_frame *frame);

int	load_animation(t_string file_path, t_animation **animation_ref)
{
	t_sprite_sheet	*sprite_sheet;
	t_animation		*animation;
	int				result;

	if (!file_path || !animation_ref)
		return (EMPTY_PTR_ERR);
	animation = create_animation(FRAMES_COUNT, ANIMATION_DELAY, true);
	if (!animation)
		return (MALLOC_FAIL_ERR);
	sprite_sheet = mlx_load_png(file_path);
	if (!sprite_sheet)
		return (destroy_animation(&animation), MLX_ERR);
	result = load_frames(sprite_sheet, animation);
	mlx_delete_texture(sprite_sheet);
	if (result != SUCCESS)
		return (destroy_animation(&animation), result);
	*animation_ref = animation;
	return (SUCCESS);
}

static int	load_frames(t_sprite_sheet *sprite_sheet, t_animation *animation)
{
	t_frame	*frame;
	int		i;
	int		sprite_width;
	int		sprite_height;

	sprite_width = sprite_sheet->width / FRAMES_COUNT;
	sprite_height = sprite_sheet->height;
	i = 0;
	while (i < animation->frames_count)
	{
		frame = create_frame(sprite_width, sprite_height);
		if (!frame)
			return (MALLOC_FAIL_ERR);
		copy_pixels(sprite_sheet, i * frame->width, frame);
		animation->frames[i] = frame;
		i++;
	}
	return (SUCCESS);
}

static void	copy_pixels(t_sprite_sheet *sprite_sheet,
	int sprite_sheet_x, t_frame *frame)
{
	const int	bytes_per_row = frame->bytes_per_pixel * frame->width;
	t_pixel		*frame_position;
	t_pixel		*sprite_sheet_position;
	int			y;
	int			sprite_sheet_offset;

	frame_position = &frame->pixels[0];
	sprite_sheet_offset = sprite_sheet_x * frame->bytes_per_pixel;
	sprite_sheet_position = &sprite_sheet->pixels[sprite_sheet_offset];
	y = 0;
	while (y < (int)frame->height)
	{
		ft_memcpy(frame_position, sprite_sheet_position, bytes_per_row);
		sprite_sheet_position += sprite_sheet->width * frame->bytes_per_pixel;
		frame_position += bytes_per_row;
		y++;
	}
}
