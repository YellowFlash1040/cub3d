/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:14:20 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 16:43:16 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas_builder.h"

int	build_canvas(t_canvas **canvas_ref, mlx_t *mlx)
{
	t_canvas	*canvas;

	if (!canvas_ref || !*canvas_ref)
		return (EMPTY_PTR_ERR);
	canvas = *canvas_ref;
	canvas->image = mlx_new_image(mlx, canvas->size.width, canvas->size.height);
	if (!canvas->image)
		return (destroy_canvas(canvas_ref), MLX_ERR);
	canvas->pixels = canvas->image->pixels;
	return (SUCCESS);
}
