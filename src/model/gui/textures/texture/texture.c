/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:47:21 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/30 18:50:48 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

t_color	get_texture_pixel(t_texture *texture, int x, int y)
{
	int	bytes_offset;

	bytes_offset = (y * texture->width + x) * texture->bytes_per_pixel;
	return (*(t_color *)(texture->pixels + bytes_offset));
}

/*
Fun fact:

return (*(t_color *)(texture->pixels + bytes_offset));

and 

return (texture->pixels[bytes_offset]);

is not the same as one might think,

since the data inside texture->pixels is stored as bytes
meaning texture->pixels[bytes_offset] is a (uint8_t *) which is 1 byte
meaning that in the second case you are getting only 1 byte (8 bits)
and translating that into a t_color (32 bits)

while in the first case you are getting pointer
to the position of the first byte of the color, and taking 4 bytes,
because with the (t_color *) you are explicitly telling that you 
want to take size of the t_color bytes (which is equal to 4)
*/
