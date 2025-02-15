/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:23:24 by crigonza          #+#    #+#             */
/*   Updated: 2023/11/21 09:50:20 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "structs.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_W 1152
# define WIN_H 864
# define TILE 10

// check_map//
int		check_map_chars(t_map map);
int		check_first_and_last(char *first, char *last);
int		check_map_point(char **map, int y, int x);
int		check_map(t_map map);
// check_utils.c//
int		check_file_colors(int *tex_and_col, char *file);
int		check_file_tex(char *file);
int		check_args(int argc, char **argv);
// checker.c//
int		check_player_duplicate(t_game *game);
int		check_player(t_game *game);
int		check_colors(t_data *data, t_game *game);
int		load_textures(t_data *data, t_game *game);
int		check_data(t_data *data, t_game *game);
// controls.c//
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	rotate(t_player *player, float angle);
// draw.c//
void	draw_sky_and_floor(t_game *game, int x);
int		dim_color(t_color *color, double dist);
void	draw_stripe(t_game *game, int x, int start, int end);
void	get_wall_height(t_game *game, int x);
// free_utils//
void	game_over(t_game *game);
void	free_data(t_data *data);
// hooks.c//
void	key_hook(mlx_key_data_t keydata, void *params);
void	main_hook(void *params);
// initialize.c//
void	data_init(t_data *data);
// main.c//
void	parse_and_check(t_game *game, char *file);
int		main(int argc, char **argv);
// parser_utils//
int		spaces_line(char *line);
char	*get_path(char *line);
t_color	get_color(char *rgb);
void	set_plane(t_player *player, char dir);
void	set_dir(t_player *player, char dir);
// parser.c//
void	map_data(t_data *data, int fd, int lines);
int		is_valid_color(char *line);
void	parse_textures_aux(t_data *data, char *line);
void	parse_textures(t_data *data, int fd);
void	parse_map(t_data *data, int fd, t_game *game);
// raycast.c//
void	ray_refresh(t_ray *ray, t_player *player, int x);
void	ray_dir(t_ray *ray, t_player *player);
void	check_hit(t_game *game);
void	set_dist(t_game *game);
void	raycast(t_game *game);
// texture.c//
t_color	get_texture_pixel(mlx_texture_t *texture, int x, int y);
void	get_wall_texture(t_game *game);
void	set_tex_params(t_wall_tex *wall_tex, t_ray *ray);
// utils.c//
char	*get_next_line(int fd);
int		get_rgba(int r, int g, int b, int a);
int		check_map_ini(char *line);

#endif
