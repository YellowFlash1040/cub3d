/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:16:34 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 11:41:52 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frame.h"

t_frame	*init_frame(void)
{
	t_frame	*frame;

	frame = (t_frame *)malloc(sizeof(t_frame));
	if (!frame)
		return (NULL);
	frame->width = 0;
	frame->height = 0;
	frame->pixels = NULL;
	frame->bytes_per_pixel = BYTES_PER_PIXEL;
	return (frame);
}

int	build_frame(t_frame **frame_ref, int width, int height)
{
	t_frame	*frame;
	int		bytes_count;

	if (!frame_ref || !*frame_ref)
		return (EMPTY_PTR_ERR);
	frame = *frame_ref;
	frame->width = width;
	frame->height = height;
	bytes_count = sizeof(t_pixel) * width * height * frame->bytes_per_pixel;
	frame->pixels = (t_pixel *)malloc(bytes_count);
	ft_bzero(frame->pixels, bytes_count);
	if (!frame->pixels)
		return (MALLOC_FAIL_ERR);
	return (SUCCESS);
}

t_frame	*create_frame(int width, int height)
{
	t_frame	*frame;
	int		result;

	frame = init_frame();
	if (!frame)
		return (NULL);
	result = build_frame(&frame, width, height);
	if (result != SUCCESS)
		return (free(frame), NULL);
	return (frame);
}

void	destroy_frame(t_frame **frame_ref)
{
	t_frame	*frame;

	if (!frame_ref || !*frame_ref)
		return ;
	frame = *frame_ref;
	if (frame->pixels)
		free(frame->pixels);
	free(frame);
	*frame_ref = NULL;
}
