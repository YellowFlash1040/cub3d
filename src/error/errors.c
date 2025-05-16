/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:56:02 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/16 14:57:44 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

const char	*get_err_msg(int err_code)
{
	if (err_code == MLX_ERR)
		return (mlx_strerror(mlx_errno));
	if (err_code == MALLOC_FAIL_ERR)
		return ("malloc() syscall failure");
	return ("Error");
}

void	print_err_msg(const char *message)
{
	write(STDERR_FILENO, message, ft_strlen((char *)message));
	write(STDERR_FILENO, "\n", 1);
}
