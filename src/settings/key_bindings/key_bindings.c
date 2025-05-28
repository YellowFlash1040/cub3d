/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:35:32 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/28 15:37:25 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_bindings.h"

bool	is_movement_key(keys_t key)
{
	if (key == KEY_UP)
		return (true);
	if (key == KEY_DOWN)
		return (true);
	if (key == KEY_LEFT)
		return (true);
	if (key == KEY_RIGHT)
		return (true);
	return (false);
}
