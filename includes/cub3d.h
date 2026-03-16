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
# define RESIZE false

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	move_speed;
	double	rot_speed;
}	t_player;

typedef struct s_input
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}	t_input;

typedef struct s_game
{
	mlx_t			*mlx;
	int				floor_color[3];
	int				celing_color[3];
	char			**map;
	t_player		player;
	t_input			input;
	mlx_image_t		*img;
}	t_game;

void	init_game(t_game *game);

void	validate_input(t_game *game, int argc, char *filename);

void	render(void *param);
void	render_frame(t_game *game);

void	handle_key(mlx_key_data_t keydata, void *param);

void	cleanup(t_game *game);
void	close_window(void *param);
void	error_exit(t_game *game, char *msg);

#endif