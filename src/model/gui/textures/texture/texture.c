/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:47:21 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/01 15:14:49 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

t_color	get_texture_pixel(t_texture *texture, int x, int y)
{
	uint8_t		*pixel;
	t_channel	r;
	t_channel	g;
	t_channel	b;
	t_channel	a;

	pixel = texture->pixels
		+ (y * texture->width + x) * texture->bytes_per_pixel;
	r = pixel[0];
	g = pixel[1];
	b = pixel[2];
	a = pixel[3];
	return (r << 24 | g << 16 | b << 8 | a);
}

/*
Fun fact 1:

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

/*
Fun fact 2:

return (*(t_color *)(texture->pixels + bytes_offset));

doesn't work as you'd expect it to work either because of the 
endianness. I have a .md file with explanations inside:
.other/notes/colors folder

that's why you have to use manual bit assembly instead
color = r << 24 | g << 16 | b << 8 | a;
*/

/*-----------------------------------------------------------*/
/*----------MORE READABLE VERSION OF THE CODE----------------*/
/*-----------------------------------------------------------
More readable version of the code 
which is not possible to use because of the norminette:

t_color	get_texture_pixel(t_texture *texture, int x, int y)
{
	int			bytes_offset;
	t_channel*	pixel;
	t_channel	r, g, b, a;
	t_color		color;

	bytes_offset = (y * texture->width + x) * texture->bytes_per_pixel;
	pixel = texture->pixels + bytes_offset;

	r = pixel[0];
	g = pixel[1];
	b = pixel[2];
	a = pixel[3];

	color = r << 24 | g << 16 | b << 8 | a;
	
	return (color);
}
*/
