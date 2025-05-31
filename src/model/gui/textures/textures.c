/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:28:45 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/31 16:28:47 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

t_textures	*init_textures(void)
{
	t_textures	*textures;

	textures = (t_textures *)malloc(sizeof(t_textures));
	if (!textures)
		return (NULL);
	textures->ceiling = NULL;
	textures->floor = NULL;
	textures->north_wall = NULL;
	textures->south_wall = NULL;
	textures->west_wall = NULL;
	textures->east_wall = NULL;
	return (textures);
}

void	destroy_textures(t_textures **textures_ref)
{
	t_textures	*textures;

	if (!textures_ref || !*textures_ref)
		return ;
	textures = *textures_ref;
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
	free(textures);
	*textures_ref = NULL;
}
