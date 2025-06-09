/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:35:32 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/02 14:21:53 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_bindings.h"

bool	is_movement_key(keys_t key)
{
	if (key == KEY_MOVE_FORWARD)
		return (true);
	if (key == KEY_MOVE_BACKWARD)
		return (true);
	if (key == KEY_MOVE_LEFT)
		return (true);
	if (key == KEY_MOVE_RIGHT)
		return (true);
	return (false);
}

bool	is_rotation_key(keys_t key)
{
	if (key == KEY_ROTATE_LEFT)
		return (true);
	if (key == KEY_ROTATE_RIGHT)
		return (true);
	return (false);
}
