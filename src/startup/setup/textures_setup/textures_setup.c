/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:47:36 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/13 14:43:28 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures_setup.h"

int	setup_textures(t_textures *textures, t_configuration *config)
{
	int	result;

	setup_surfaces(textures, config);
	// result = setup_walls(textures, config);
	// if (result != SUCCESS)
	// 	return (result);
	result = setup_door(textures, config);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

void	setup_surfaces(t_textures *textures, t_configuration *config)
{
	textures->ceiling->type = CEILING;
	textures->ceiling->color = config->ceiling_color;
	textures->floor->type = FLOOR;
	textures->floor->color = config->floor_color;
}

int	setup_walls(t_textures *textures, t_configuration *config)
{
	t_string	filepath;

	filepath = config->textures[TEXTURE_NORTH_WALL];
	textures->north_wall->texture = mlx_load_png(filepath);
	if (!textures->north_wall->texture)
		return (MLX_ERR);
	filepath = config->textures[TEXTURE_SOUTH_WALL];
	textures->south_wall->texture = mlx_load_png(filepath);
	if (!textures->south_wall->texture)
		return (MLX_ERR);
	filepath = config->textures[TEXTURE_WEST_WALL];
	textures->west_wall->texture = mlx_load_png(filepath);
	if (!textures->west_wall->texture)
		return (MLX_ERR);
	filepath = config->textures[TEXTURE_EAST_WALL];
	textures->east_wall->texture = mlx_load_png(filepath);
	if (!textures->east_wall->texture)
		return (MLX_ERR);
	return (SUCCESS);
}

int	setup_door(t_textures *textures, t_configuration *config)
{
	textures->door->texture = mlx_load_png(config->textures[TEXTURE_DOOR]);
	if (!textures->door->texture)
		return (MLX_ERR);
	return (SUCCESS);
}
