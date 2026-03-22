/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 03:29:26 by gustaoli          #+#    #+#             */
/*   Updated: 2026/03/21 23:36:08 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_rgb(t_game *game, char *line, int rgb[3]);

void	parse_color(t_game *game, char *line)
{
	int	rgb[3];
	int	i;
	int	y;

	i = 1;
	y = 0;
	while (y < 3 && line[++i])
	{
		rgb[y] = ft_atoi(&(line[i]));
		if (rgb[y] > 255 || !ft_isdigit(line[i]))
			error_exit(game, ".cub file invalid color value.");
		while (line[i] && (line[i] != ',' && line[i] != '\n'))
		{
			if (!ft_isdigit(line[i]) || i > 12)
				error_exit(game, ".cub file config isn't correctly definined.");
			i++;
		}
		y++;
	}
	if (y != 3 || line[i])
		error_exit(game, ".cub file config isn't correctly definined.");
	set_rgb(game, line, rgb);
}

static void	set_rgb(t_game *game, char *line, int rgb[3])
{
	if (*line == 'F')
		game->floor_color = rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | 0xFF;
	else if (*line == 'C')
		game->celing_color = rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | 0xFF;
}
