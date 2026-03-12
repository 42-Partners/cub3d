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

# define WIDTH 800
# define HEIGHT 800
# define RESIZE true

typedef struct s_game
{
	mlx_t	*mlx;
}	t_game;

void	init_game(t_game *game);

void	close_window(void *param);

int		open_map(t_game *game, char *filename);

void	cleanup(t_game *game);
void	error_exit(t_game *game, char *msg);

#endif