/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_builder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:04:01 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/29 16:26:41 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures_builder.h"

int	build_textures(t_textures *textures)
{
	if (!textures)
		return (EMPTY_PTR_ERR);
	textures->ceiling = init_surface();
	if (!textures->ceiling)
		return (destroy_textures(&textures), MALLOC_FAIL_ERR);
	textures->floor = init_surface();
	if (!textures->ceiling)
		return (destroy_textures(&textures), MALLOC_FAIL_ERR);
	textures->north_wall = init_wall();
	if (!textures->north_wall)
		return (destroy_textures(&textures), MALLOC_FAIL_ERR);
	textures->south_wall = init_wall();
	if (!textures->south_wall)
		return (destroy_textures(&textures), MALLOC_FAIL_ERR);
	textures->west_wall = init_wall();
	if (!textures->west_wall)
		return (destroy_textures(&textures), MALLOC_FAIL_ERR);
	textures->east_wall = init_wall();
	if (!textures->east_wall)
		return (destroy_textures(&textures), MALLOC_FAIL_ERR);
	return (SUCCESS);
}
