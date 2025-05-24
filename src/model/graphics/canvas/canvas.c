/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:46:45 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/24 19:52:42 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

t_canvas	*init_canvas(t_size size, t_point position)
{
	t_canvas	*canvas;

	canvas = (t_canvas *)malloc(sizeof(t_canvas));
	if (!canvas)
		return (NULL);
	canvas->size = size;
	canvas->position = position;
	canvas->pixels = NULL;
	return (canvas);
}

int	create_canvas(mlx_t *mlx, t_canvas **canvas_ref, t_size size,
	t_point position)
{
	int			result;
	mlx_image_t	*image;
	t_canvas	*canvas;

	if (!mlx)
		return (EMPTY_PTR_ERR);
	canvas = init_canvas(size, position);
	if (!canvas)
		return (MALLOC_FAIL_ERR);
	image = mlx_new_image(mlx, canvas->size.width, canvas->size.height);
	if (!image)
		return (MLX_ERR);
	canvas->image = image;
	canvas->pixels = image->pixels;
	result = mlx_image_to_window(mlx, image, canvas->position.x,
			canvas->position.y);
	if (result == -1)
		return (MLX_ERR);
	*canvas_ref = canvas;
	return (SUCCESS);
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
