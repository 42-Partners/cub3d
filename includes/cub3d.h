/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:04:23 by gustaoli          #+#    #+#             */
/*   Updated: 2026/03/10 20:04:23 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "MLX42/MLX42.h"

# include <stdio.h>

# define WIDTH 1200
# define HEIGHT 800
# define CAMERA_HEIGHT -75

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	orientation;
	double	move_speed;
	double	rot_speed;
}	t_player;

typedef struct s_map
{
	char	**map;
	char	**copy;
	int		rows;
	int		cols;
	int		map_fd;
}	t_map;

typedef struct s_input
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}	t_input;

typedef struct s_textures
{
	mlx_texture_t	*so;
	mlx_texture_t	*no;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
}	t_textures;

typedef struct s_game
{
	mlx_t			*mlx;
	int				floor_color;
	int				celing_color;
	t_map			map;
	t_player		player;
	t_input			input;
	t_textures		textures;
	mlx_image_t		*img;
}	t_game;

void	init_game(t_game *game);

void	validate_input(t_game *game, int argc, char *filename);
bool	parse_textures(t_game *game, char *file_name, int flag);
void	validate_config(t_game *game);
void	validate_map(t_game *game);
bool	parse_color(t_game *game, char *line);

void	render(void *param);
void	render_frame(t_game *game);
void	raycast(t_game *game);

void	handle_key(mlx_key_data_t keydata, void *param);

void	cleanup(t_game *game);
void	error_exit(t_game *game, char *msg);
void	close_window(void *param);
void	clean_gnl(int fd);

#endif