/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_builder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:02:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 17:02:58 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

static int	build_surfaces(t_textures *textures);
static int	build_walls(t_textures *textures);
static int	build_door(t_textures *textures);

int	build_textures(t_textures **textures_ref)
{
	t_textures	*textures;
	int			result;

	if (!textures_ref || !*textures_ref)
		return (EMPTY_PTR_ERR);
	textures = *textures_ref;
	result = build_surfaces(textures);
	if (result != SUCCESS)
		return (destroy_textures(textures_ref), result);
	result = build_walls(textures);
	if (result != SUCCESS)
		return (destroy_textures(textures_ref), result);
	result = build_door(textures);
	if (result != SUCCESS)
		return (destroy_textures(textures_ref), result);
	return (SUCCESS);
}

static int	build_surfaces(t_textures *textures)
{
	textures->ceiling = init_surface();
	if (!textures->ceiling)
		return (MALLOC_FAIL_ERR);
	textures->floor = init_surface();
	if (!textures->ceiling)
		return (MALLOC_FAIL_ERR);
	return (SUCCESS);
}

static int	build_walls(t_textures *textures)
{
	textures->north_wall = init_wall();
	if (!textures->north_wall)
		return (MALLOC_FAIL_ERR);
	textures->south_wall = init_wall();
	if (!textures->south_wall)
		return (MALLOC_FAIL_ERR);
	textures->west_wall = init_wall();
	if (!textures->west_wall)
		return (MALLOC_FAIL_ERR);
	textures->east_wall = init_wall();
	if (!textures->east_wall)
		return (MALLOC_FAIL_ERR);
	return (SUCCESS);
}

static int	build_door(t_textures *textures)
{
	textures->door = init_door();
	if (!textures->door)
		return (MALLOC_FAIL_ERR);
	return (SUCCESS);
}
