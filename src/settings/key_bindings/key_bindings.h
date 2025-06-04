/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:44:39 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/04 16:23:09 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_BINDINGS_H
# define KEY_BINDINGS_H

# include <MLX42/MLX42.h>

# define KEY_MOVE_FORWARD MLX_KEY_W
# define KEY_MOVE_BACKWARD MLX_KEY_S
# define KEY_MOVE_LEFT MLX_KEY_A
# define KEY_MOVE_RIGHT MLX_KEY_D

# define KEY_ROTATE_LEFT MLX_KEY_LEFT
# define KEY_ROTATE_RIGHT MLX_KEY_RIGHT

# define KEY_CLOSE_WINDOW MLX_KEY_ESCAPE

# define KEY_TOGGLE_MINIMAP MLX_KEY_TAB
# define KEY_TOGGLE_DOOR MLX_KEY_E

bool	is_movement_key(keys_t key);
bool	is_rotation_key(keys_t key);

#endif
