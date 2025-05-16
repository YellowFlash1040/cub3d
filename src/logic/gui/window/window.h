/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:34:50 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/16 16:57:55 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "status_codes.h"
# include <MLX42/MLX42.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

int		connect_to_display(mlx_t **mlx_out);
void	keep_app_running(mlx_t *mlx);

#endif
