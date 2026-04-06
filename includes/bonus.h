/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:22:28 by gustaoli          #+#    #+#             */
/*   Updated: 2026/04/05 21:36:20 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BONUS_H
# define BONUS_H

# include "MLX42/MLX42.h"

# include <stdio.h>
# include <sys/time.h>

# define WIDTH 1200
# define HEIGHT 800


typedef struct s_images
{
	mlx_image_t	*scene00_a;
	mlx_image_t	*scene00_b;
	mlx_image_t	*scene00_c;
	mlx_image_t	*scene00_d;
}	t_images;

typedef struct s_textures
{
	mlx_texture_t	*scene00_a;
	mlx_texture_t	*scene00_b;
	mlx_texture_t	*scene00_c;
	mlx_texture_t	*scene00_d;
}	t_textures;

typedef struct s_game
{
	mlx_t			*mlx;
	long			start_timestamp;
	t_textures		textures;
	t_images		images;
	mlx_image_t		*img;
}	t_game;

void	init_window(t_game *game);

long	get_time(void);

void	error_exit(t_game *game, char *msg);

#endif