/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:34:50 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/26 15:42:47 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <MLX42/MLX42.h>
# include "settings.h"
# include "errors.h"

int		connect_to_display(mlx_t **mlx_out);
void	keep_app_running(mlx_t *mlx);

#endif
