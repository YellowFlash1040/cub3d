/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:46:39 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/27 17:52:44 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lifecycle.h"

static void	run(void *param);

int	keep_app_running(t_app *app)
{
	bool	success;

	success = mlx_loop_hook(app->mlx, run, app);
	if (!success)
		return (MLX_ERR);
	mlx_loop(app->mlx);
	return (SUCCESS);
}

static void	run(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	handle_keyboard(app);
	handle_mouse(app);
	render_frame(app);
}
