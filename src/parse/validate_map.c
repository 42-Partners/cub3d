/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:37:19 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/19 20:14:20 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validate_walls(t_game *game, int i);
static void	validate_row(t_game *game, int *spawn, int i);
static int	validate_char(char c);

void	validate_map(t_game *game)
{
	int		spawn;
	int		i;

	spawn = 0;
	i = 0;
	while (game->map.map[i])
	{
		validate_walls(game, i);
		validate_row(game, &spawn, i);
		i++;
	}
	if (spawn != 1)
		error_exit(game, "Invalid map");
}

static void	validate_walls(t_game *game, int i)
{
	char	*line;
	int		len;
	int		j;

	line = game->map.map[i];
	len = ft_strlen(line);
	j = 0;
	while (ft_isspace(line[j]))
		j++;
	if (i == 0 || i == (game->map.rows - 1))
	{
		while (line[j])
		{
			if (line[j] != '1')
				error_exit(game, "Invalid map");
			j++;
		}
	}
	else if (line[j] != '1' || line[len - 1] != '1')
		error_exit(game, "Invalid map");
}

static void	validate_row(t_game *game, int *spawn, int i)
{
	char	c;
	int		j;

	j = 0;
	while (game->map.map[i][j])
	{
		c = game->map.map[i][j];
		if (!validate_char(c))
			error_exit(game, "Invalid map");
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			game->player.pos_x = i;
			game->player.pos_y = j;
			game->player.orientation = game->map.map[i][j];
			(*spawn)++;
		}
		j++;
	}
}

static int	validate_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ');
}
