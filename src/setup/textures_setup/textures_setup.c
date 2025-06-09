/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:47:36 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/07 21:42:00 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures_setup.h"

int	setup_textures(t_textures *textures, t_settings *settings)
{
	int	result;

	setup_surfaces(textures, settings);
	result = setup_walls(textures, settings);
	if (result != SUCCESS)
		return (result);
	result = setup_door(textures, settings);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

void	setup_surfaces(t_textures *textures, t_settings *settings)
{
	textures->ceiling->type = CEILING;
	textures->ceiling->color = settings->ceiling_color;
	textures->floor->type = FLOOR;
	textures->floor->color = settings->floor_color;
}

int	setup_walls(t_textures *textures, t_settings *settings)
{
	textures->north_wall->direction = NORTH;
	textures->north_wall->texture = mlx_load_png(settings->north_wall_filepath);
	if (!textures->north_wall->texture)
		return (MLX_ERR);
	textures->south_wall->direction = SOUTH;
	textures->south_wall->texture = mlx_load_png(settings->south_wall_filepath);
	if (!textures->south_wall->texture)
		return (MLX_ERR);
	textures->west_wall->direction = WEST;
	textures->west_wall->texture = mlx_load_png(settings->west_wall_filepath);
	if (!textures->west_wall->texture)
		return (MLX_ERR);
	textures->east_wall->direction = EAST;
	textures->east_wall->texture = mlx_load_png(settings->east_wall_filepath);
	if (!textures->east_wall->texture)
		return (MLX_ERR);
	return (SUCCESS);
}

int	setup_door(t_textures *textures, t_settings *settings)
{
	textures->door->texture = mlx_load_png(settings->door_filepath);
	if (!textures->door->texture)
		return (MLX_ERR);
	return (SUCCESS);
}
