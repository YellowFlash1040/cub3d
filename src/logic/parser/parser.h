/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbom <rbom@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/15 15:39:09 by rbom          #+#    #+#                 */
/*   Updated: 2025/06/26 17:33:07 by rbom          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "MLX42/MLX42.h"
# include "get_next_line.h"
# include "ft_string.h"
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

# define DEFAULT_DOOR "./assets/textures/animated/walls/door1.png"
# define DEFAULT_SPRITE "./assets/textures/animated/sprites/spr1.png"

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
	char	*error[19];
	char	*file;
	int		fd;
	char	*line;
	bool	dir_check[9];
	char	*dir[8];
	int		map_x;
	int		map_y;
	int		temp_y;
	bool	spawn;
	char	*clean_wall[6];
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
	int		sprites_count;
	t_xy	*sprites;
}	t_data;

void	init_error_message(t_data *data);
void	init_map_data(t_data *data);
void	free_null(void	**ptr);
void	open_fd(t_data *data, char *file, int *fd);
void	close_fd(t_data *data, int *fd);

void	free_all(t_data *data, uint8_t exit_status);
void	exit_all(t_data *data, uint8_t exit_status);
void	check_number_args(t_data *data, int argc, char **argv);
void	check_extension(t_data *data, char *file, char *ext);
void	reset_dir(t_data *data);

bool	check_dir_complete(t_data *data);
bool	ft_isspace(char c);
bool	empty_line(char *str);
void	check_texture(t_data *data, int i);
bool	ft_isdigit(char c);

bool	check_wall(t_data *data, int d, int i);
void	atouint8_check(t_data *data, int i);
int		check_rgb(t_data *data, int i, bool last);
bool	check_floor(t_data *data, int d, int i);
void	check_dir(t_data *data);

void	check_map_line(t_data *data);
void	check_map(t_data *data);
void	check_dir_map(t_data *data);
void	init_temp_clean_map(t_data *data);
bool	scrape_wall(t_data *data, int d, int i);

uint8_t	atouint8(t_data *data, int i);
int		scrape_floor_loop(t_data *data, int f, int i, char c);
bool	scrape_floor(t_data *data, int d, int i);
void	scrape_dir(t_data *data);
void	scrape_map(t_data *data);

void	scrape_dir_map(t_data *data);
bool	flood_fill(t_data *data, int x, int y, bool stop);
void	generate_clean_map(t_data *data);
void	resize_map_y(t_data *data);
void	resize_map_x(t_data *data);

void	scrape_spawn(t_data *data, int x, int y);
void	resize_map(t_data *data);
void	count_sprite(t_data *data);
void	scrape_sprite(t_data *data);
void	parse_all(t_data *data, int argc, char **argv);

#endif