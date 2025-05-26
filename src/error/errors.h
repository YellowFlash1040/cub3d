/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:55:22 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/26 15:42:09 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <MLX42/MLX42.h>
# include <unistd.h>
# include "ft_string.h"

# define SUCCESS EXIT_SUCCESS
# define FAILURE EXIT_FAILURE

# define MLX_ERR 10
# define MALLOC_FAIL_ERR 11
# define EMPTY_PTR_ERR 12
# define INVALID_VALUE 13

const char	*get_err_msg(int err_code);
void		print_err_msg(const char *message);

#endif
