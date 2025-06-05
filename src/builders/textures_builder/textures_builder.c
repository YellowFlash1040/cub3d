/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_builder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:04:01 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/05 14:46:26 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures_builder.h"

static void	destroy_temp(t_textures *textures);

int	build_textures(t_textures *textures)
{
	if (!textures)
		return (EMPTY_PTR_ERR);
	textures->ceiling = init_surface();
	if (!textures->ceiling)
		return (destroy_temp(textures), MALLOC_FAIL_ERR);
	textures->floor = init_surface();
	if (!textures->ceiling)
		return (destroy_temp(textures), MALLOC_FAIL_ERR);
	textures->north_wall = init_wall();
	if (!textures->north_wall)
		return (destroy_temp(textures), MALLOC_FAIL_ERR);
	textures->south_wall = init_wall();
	if (!textures->south_wall)
		return (destroy_temp(textures), MALLOC_FAIL_ERR);
	textures->west_wall = init_wall();
	if (!textures->west_wall)
		return (destroy_temp(textures), MALLOC_FAIL_ERR);
	textures->east_wall = init_wall();
	if (!textures->east_wall)
		return (destroy_temp(textures), MALLOC_FAIL_ERR);
	textures->door = init_door();
	if (!textures->door)
		return (destroy_temp(textures), MALLOC_FAIL_ERR);
	return (SUCCESS);
}

static void	destroy_temp(t_textures *textures)
{
	if (!textures)
		return ;
	if (textures->ceiling)
		destroy_surface(&textures->ceiling);
	if (textures->floor)
		destroy_surface(&textures->floor);
	if (textures->north_wall)
		destroy_wall(&textures->north_wall);
	if (textures->south_wall)
		destroy_wall(&textures->south_wall);
	if (textures->west_wall)
		destroy_wall(&textures->west_wall);
	if (textures->east_wall)
		destroy_wall(&textures->east_wall);
	if (textures->door)
		destroy_door(&textures->door);
}
