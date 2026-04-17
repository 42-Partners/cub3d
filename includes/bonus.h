/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:22:28 by gustaoli          #+#    #+#             */
/*   Updated: 2026/04/17 01:35:20 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "MLX42/MLX42.h"

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/time.h>

# define WIDTH 1200
# define HEIGHT 800

typedef struct s_images
{
	mlx_image_t	*cursor_a;
	mlx_image_t	*cursor_b;
	mlx_image_t	*scene00_a;
	mlx_image_t	*scene00_b;
	mlx_image_t	*scene00_c;
	mlx_image_t	*scene00_d;
	mlx_image_t	*scene01_a;
	mlx_image_t	*scene01_b;
	mlx_image_t	*scene01_c;
	mlx_image_t	*scene01_d;
	mlx_image_t	*scene01_e;
	mlx_image_t	*scene02_a;
	mlx_image_t	*scene02_b;
	mlx_image_t	*scene02_c;
	mlx_image_t	*scene02_d;
	mlx_image_t	*scene02_e;
	mlx_image_t	*scene02_f;
	mlx_image_t	*scene02_g;
	mlx_image_t	*scene02_h;
}	t_images;

typedef struct s_textures
{
	mlx_texture_t	*cursor_a;
	mlx_texture_t	*cursor_b;
	mlx_texture_t	*scene00_a;
	mlx_texture_t	*scene00_b;
	mlx_texture_t	*scene00_c;
	mlx_texture_t	*scene00_d;
	mlx_texture_t	*scene01_a;
	mlx_texture_t	*scene01_b;
	mlx_texture_t	*scene01_c;
	mlx_texture_t	*scene01_d;
	mlx_texture_t	*scene01_e;
	mlx_texture_t	*scene02_a;
	mlx_texture_t	*scene02_b;
	mlx_texture_t	*scene02_c;
	mlx_texture_t	*scene02_d;
	mlx_texture_t	*scene02_e;
	mlx_texture_t	*scene02_f;
	mlx_texture_t	*scene02_g;
	mlx_texture_t	*scene02_h;
}	t_textures;

typedef struct s_game
{
	mlx_t			*mlx;
	long			start_timestamp;
	t_textures		textures;
	t_images		images;
	mlx_image_t		*img;
	mlx_image_t		*fade;
	bool			on_scene;
	bool			start;
	int				cursor_x;
	int				cursor_y;
}	t_game;

void	init_window(t_game *game);
void	handle_key(mlx_key_data_t keydata, void *param);
long	get_time(void);
void	close_window(void *param);
void	load_textures(t_game *game);
void	load_images(t_game *game);
void	error_exit(t_game *game, char *msg);
void	handle_scene(t_game *game);
void	load_menu(void *param);
void	put_background(mlx_image_t *img, uint32_t color);
void	fade_out(t_game *game, int op);
void	mouse_hook(double x, double y, void *param);
void	draw_frame(t_game *game, int frame, int pos_x, int pos_y);
void	draw_image_to_image(mlx_image_t *dst,
			mlx_image_t *src, int pos_x, int pos_y);
void	render_cursor(t_game *game, mlx_image_t *cursor);
void	handle_click_scene01(t_game *game);
void	handle_click_scene02(t_game *game);
void	run_background(t_game *game, long e);
void	cleanup(t_game *game);
void	load_game(t_game *game, int map);

void	scene00(t_game *game);
void	scene01(t_game *game);
void	scene02(t_game *game);

#endif