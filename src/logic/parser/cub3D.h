/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:39:09 by rbom              #+#    #+#             */
/*   Updated: 2025/06/04 18:43:56 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h> 
# include <sys/time.h>
# include <sys/types.h> 
# include <unistd.h>

# include <stdbool.h>
# include <limits.h>

# include "ft_string.h"
# include "get_next_line.h"

typedef struct s_rgb
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_rgb;

typedef struct s_xy
{
	uint16_t	x;
	uint16_t	y;
}	t_xy;

typedef struct s_data
{
	char	*error[22];
	char	*file;
	int		fd;
	char	*line;
	bool	dir_check[6];
	char	*dir[6];
	int		fd_check;
	int		map_x;
	int		map_y;
	int		temp_y;
	bool	spawn;
	char	*texture;
	char	*clean_wall[4];
	t_rgb	clean_floor[2];
	char	**temp_map;
	char	**clean_map;
	t_xy	clean_map_size;
	t_xy	resize_spawn;
	char	resize_spawn_dir;
	t_xy	start;
	t_xy	end;
	t_xy	resize_map_size;
	char	**resize_map;
}	t_data;

typedef struct complete
{
	char	*wall[4];
	t_rgb	floor[2];
	char	**map;
	t_xy	map_size;
	t_xy	spawn;
	uint8_t	spawn_dir;
}	t_complete;

void	init_error_message(t_data *data);
void	init_map_data(t_data *data);
void	free_null(void	**ptr);
void	free_all(t_data *data, uint8_t exit_status);
void	exit_all(t_data *data, uint8_t exit_status);

void	check_number_args(t_data *data, int argc, char **argv);
void	check_extension(t_data *data, char *str, char *ext, int exit_status);
void	check_input(t_data *data, int argc, char **argv);
void	open_fd(t_data *data, char *file, int *fd, int exit_status);
void	close_fd(t_data *data, int fd, int exit_status);

bool	ft_isspace(char c);
bool	empty_line(char *str);
bool	check_dir_complete(t_data *data);
bool	ft_isdigit(char c);
void	check_texture(t_data *data, int i);

bool	check_dir_wall_loop(t_data *data, int w, int i);
bool	check_dir_wal(t_data *data);
void	atouint8_check(t_data *data, int i);
int		check_loop_skip(t_data *data, int i, bool last);
bool	check_dir_floor_loop(t_data *data, int f);

bool	check_dir_floor(t_data *data);
void	check_dir(t_data *data);
void	check_map_line(t_data *data);
void	check_map(t_data *data);
void	check_dir_map(t_data *data);

void	reset_dir(t_data *data);
void	initialize_map(t_data *data);
void	scrape_texture(t_data *data, int w, int i);
bool	scrape_dir_wall_loop(t_data *data, int w);
bool	scrape_dir_wal(t_data *data);

void	atouint8(t_data *data, int f, int i, char c);
int		scrape_loop_skip(t_data *data, int f, int i, char c);
bool	scrape_dir_floor_loop(t_data *data, int f);
bool	scrape_dir_floor(t_data *data);
void	scrape_dir(t_data *data);

void	scrape_map_loop(t_data *data, int i);
void	scrape_map(t_data *data);
void	scrape_dir_map(t_data *data);
void	check_enclosure(t_data *data, int x, int y);
bool	flood_fill(t_data *data, int x, int y, bool stop);

void	clean_map(t_data *data);
void	resize_map_size_loop(t_data *data);
void	resize_map_size(t_data *data);
void	scrape_spawn(t_data *data, int x, int y);
void	resize_map(t_data *data);

#endif