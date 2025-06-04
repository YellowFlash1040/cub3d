/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:46:45 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/03 18:29:01 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

t_canvas	*init_canvas(t_size size)
{
	t_canvas	*canvas;

	canvas = (t_canvas *)malloc(sizeof(t_canvas));
	if (!canvas)
		return (NULL);
	canvas->size = size;
	canvas->position = (t_point){0};
	canvas->pixels = NULL;
	canvas->image = NULL;
	return (canvas);
}

void	destroy_canvas(t_canvas **canvas_ref)
{
	t_canvas	*canvas;

	if (!canvas_ref || !*canvas_ref)
		return ;
	canvas = *canvas_ref;
	free(canvas);
	*canvas_ref = NULL;
}

int	canvas_to_window(mlx_t *mlx, t_canvas *canvas)
{
	int	result;

	result = mlx_image_to_window(mlx, canvas->image, canvas->position.x,
			canvas->position.y);
	if (result == -1)
		return (MLX_ERR);
	return (SUCCESS);
}
