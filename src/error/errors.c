/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:56:02 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/03 17:13:00 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

const char	*get_err_msg(int err_code)
{
	if (err_code == MLX_ERR)
		return (mlx_strerror(mlx_errno));
	if (err_code == MALLOC_FAIL_ERR)
		return ("malloc() syscall failure");
	if (err_code == EMPTY_PTR_ERR)
		return ("Some function received an empty pointer as an argument");
	if (err_code == INVALID_VALUE)
		return ("Some function received an invalid value");
	return ("Unknown error");
}

void	print_err_msg(const char *message)
{
	write(STDERR_FILENO, "Error: ", 8);
	write(STDERR_FILENO, message, ft_strlen((char *)message));
	write(STDERR_FILENO, "\n", 1);
}
