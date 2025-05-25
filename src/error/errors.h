/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:55:22 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/25 15:06:02 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <MLX42/MLX42.h>
# include <unistd.h>
# include "status_codes.h"
# include "ft_string.h"

# define MLX_ERR 10
# define MALLOC_FAIL_ERR 11
# define EMPTY_PTR_ERR 12
# define INVALID_VALUE 13

const char	*get_err_msg(int err_code);
void		print_err_msg(const char *message);

#endif
