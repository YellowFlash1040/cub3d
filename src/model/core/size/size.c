/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:45:17 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/17 16:45:17 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "size.h"

t_size	*init_size(void)
{
	t_size	*size;

	size = (t_size *)malloc(sizeof(t_size));
	if (!size)
		return (NULL);
	return (size);
}

void	destroy_size(t_size **size_ref)
{
	t_size	*size;

	if (!size_ref || !*size_ref)
		return ;
	size = *size_ref;
	free(size);
	*size_ref = NULL;
}
