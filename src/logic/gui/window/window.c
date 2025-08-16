/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:34:00 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/27 18:09:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int	connect_to_display(mlx_t **mlx_out)
{
	mlx_t	*mlx;

	*mlx_out = NULL;
	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d", false);
	if (!mlx)
		return (MLX_ERR);
	*mlx_out = mlx;
	return (SUCCESS);
}
