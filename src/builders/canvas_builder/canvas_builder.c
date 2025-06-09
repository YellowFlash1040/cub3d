/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:14:20 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/03 16:27:21 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas_builder.h"

int	build_canvas(t_canvas *canvas, mlx_t *mlx)
{
	if (!canvas)
		return (EMPTY_PTR_ERR);
	canvas->image = mlx_new_image(mlx, canvas->size.width, canvas->size.height);
	if (!canvas->image)
		return (MLX_ERR);
	canvas->pixels = canvas->image->pixels;
	return (SUCCESS);
}
