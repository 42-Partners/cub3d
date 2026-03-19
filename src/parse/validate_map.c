/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:37:19 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/19 19:05:33 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_walls(t_game *game, int i);
static int	validate_row(t_game *game, int *spawn, int i);
static int	validate_char(char c);

int	validate_map(t_game *game)
{
	int		spawn;
	int		i;

	spawn = 0;
	i = 0;
	while (game->map.map[i])
	{
		if (!validate_walls(game, i))
			return (0);
		if (!validate_row(game, &spawn, i))
			return (0);
		i++;
	}
	if (spawn != 1)
		return (0);
	return (1);
}

static int	validate_walls(t_game *game, int i)
{
	char	*line;
	int		len;

	line = game->map.map[i];
	len = ft_strlen(line);
	if (i == 0 || i == (game->map.rows - 1))
	{
		while (line)
		{
			if (*line != '1')
				return (0);
			line++;
		}
	}
	else if (line[0] != '1' || line[len - 1] != '1')
		return (0);
	return (1);
}

static int	validate_row(t_game *game, int *spawn, int i)
{
	char	c;
	int		j;

	j = 0;
	while (game->map.map[i][j])
	{
		c = game->map.map[i][j];
		if (!validate_char(c))
			return (0);
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			game->player.pos_x = i;
			game->player.pos_y = j;
			game->player.orientation = game->map.map[i][j];
			(*spawn)++;
		}
		j++;
	}
	return (1);
}

static int	validate_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ');
}
