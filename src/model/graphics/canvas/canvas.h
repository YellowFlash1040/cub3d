/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:37:58 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/24 19:52:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include <MLX42/MLX42.h>
# include "point.h"
# include "size.h"
# include "pixel.h"
# include "status_codes.h"

typedef struct canvas
{
	t_size		size;
	t_point		position;
	t_pixel		*pixels;
	mlx_image_t	*image;
}	t_canvas;

t_canvas	*init_canvas(t_size size, t_point position);
void		destroy_canvas(t_canvas **canvas_ref);

int			create_canvas(mlx_t *mlx, t_canvas **canvas_ref, t_size size,
				t_point position);

#endif
