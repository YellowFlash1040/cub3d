/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:58:54 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/29 16:24:44 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H

# include "game.h"
# include "canvas.h"
# include "settings.h"
# include "textures.h"

# define APP_INIT_ERR 1

typedef struct app
{
	mlx_t		*mlx;
	t_settings	*settings;
	t_game		*game;
	t_canvas	*canvas;
	t_textures	*textures;
}				t_app;

t_app			*init_app(void);
void			destroy_app(t_app **app_ref);

#endif
