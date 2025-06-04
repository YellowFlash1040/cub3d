/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:37:58 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/03 16:59:08 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "point.h"
# include "size.h"
# include "pixel.h"
# include "errors.h"

typedef struct canvas
{
	t_size		size;
	t_point		position;
	t_pixel		*pixels;
	mlx_image_t	*image;
}	t_canvas;

t_canvas	*init_canvas(t_size size);
void		destroy_canvas(t_canvas **canvas_ref);

int			canvas_to_window(mlx_t *mlx, t_canvas *canvas);

#endif
