/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:41:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/15 15:42:34 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "surface.h"

t_surface	*init_surface(void)
{
	t_surface	*surface;

	surface = (t_surface *)malloc(sizeof(t_surface));
	if (!surface)
		return (NULL);
	surface->type = SURFACE_NONE;
	surface->color = NULL;
	return (surface);
}

void	destroy_surface(t_surface **surface_ref)
{
	t_surface	*surface;

	if (!surface_ref || !*surface_ref)
		return ;
	surface = *surface_ref;
	if (surface->color)
		destroy_color(surface->color);
	free(surface);
	*surface_ref = NULL;
}
