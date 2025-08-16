/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:27:28 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/27 18:10:19 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H

# include "key_bindings.h"
# include "movements.h"
# include "rotations.h"
# include "game.h"

void	handle_movement(mlx_t *mlx, t_game *game);
void	handle_rotation(mlx_t *mlx, t_game *game);

#endif
