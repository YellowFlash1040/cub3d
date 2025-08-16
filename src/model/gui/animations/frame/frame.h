/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:42:41 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 20:42:42 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_H
# define FRAME_H

# include <stdlib.h>
# include "errors.h"
# include "ft_memory.h"
# include "pixel.h"

# define FRAME_INIT_ERR 1

# define BYTES_PER_PIXEL 4

/**
 * @param width The width of the frame.
 * @param height The height of the frame.
 * @param pixels The literal pixel data.
 * @param bytes_per_pixel The amount of bytes in a pixel, always 4.
 */
typedef struct frame
{
	uint32_t	width;
	uint32_t	height;
	uint8_t		bytes_per_pixel;
	t_pixel		*pixels;
}	t_frame;

t_frame	*init_frame(void);
void	destroy_frame(t_frame **frame_ref);
int		build_frame(t_frame **frame_ref, int width, int height);
t_frame	*create_frame(int width, int height);

#endif
