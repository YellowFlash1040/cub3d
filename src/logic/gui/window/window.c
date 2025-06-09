/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:34:00 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/16 17:23:45 by akovtune         ###   ########.fr       */
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

void	keep_app_running(mlx_t *mlx)
{
	mlx_loop(mlx);
}
