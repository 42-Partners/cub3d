/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 05:04:28 by gustaoli          #+#    #+#             */
/*   Updated: 2026/03/19 05:04:28 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_textures(t_game *game, char *file_name, int flag)
{
	mlx_texture_t	*tex;

	if (file_name[ft_strlen(file_name) - 1] == '\n')
		file_name[ft_strlen(file_name) - 1] = 0;
	tex = mlx_load_png(file_name);
	if (!tex)
		return (false);
	if (flag == 0)
		game->textures.so = tex;
	else if (flag == 1)
		game->textures.no = tex;
	else if (flag == 2)
		game->textures.we = tex;
	else if (flag == 3)
		game->textures.ea = tex;
	return (true);
}
