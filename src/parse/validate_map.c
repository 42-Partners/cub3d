/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:05:16 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/16 12:46:28 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	add_row(t_game *game, char *row);
static bool	validate_map_elements(char **map);

int	validate_map(int map_fd, t_game *game)
{
	char	*last_line;
	char	*line;

	line = get_next_line(map_fd);
	last_line = NULL;
	game->map = ft_calloc(1, sizeof (char *));
	while (ft_strcmp("\n", line) == 0)
		line = get_next_line(map_fd);
	last_line = line;
	while (line)
	{
		if (ft_strcmp("\n", line) != 0 && ft_strcmp("\n", last_line) == 0)
			return (false);
		last_line = line;
		if (ft_strcmp("\n", line) != 0 && !add_row(game, line))
			error_exit(game, "Malloc error.");
		line = get_next_line(map_fd);
	}
	return (validate_map_elements(game->map));
}

static bool	add_row(t_game *game, char *row)
{
	int		i;
	char	**new_map;

	i = 0;
	while (game->map[i])
		i++;
	new_map = ft_realloc(
			game->map, sizeof(char *) * i, sizeof(char *) * (i + 2));
	if (!new_map)
	{
		ft_free_arr(&game->map);
		return (false);
	}
	game->map = new_map;
	game->map[i] = row;
	game->map[i + 1] = NULL;
	return (true);
}

static bool	validate_map_elements(char **map)
{
	bool	player;
	int		i;
	int		j;

	i = -1;
	player = false;
	while (map[++i])
	{
		validate_row(map[i]);
		j = -1;
		while (map[i][++j])
		{
			if ((!ft_strchr(" 10NSEW\n", map[i][j])) || ((i == 0 || j == 0)
			&& (map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != '\n')))
				return (false);
			if ((ft_strchr("NSEW", map[i][j]) && player)
				|| (map[i][j] == '\n' && i > 0 && map[i -1][j] == '0'))
				return (false);
			else if (ft_strchr("NSEW", map[i][j]))
				player = true;
			if ((ft_strchr("0NSEW", map[i][j]))
				&& (map[i - 1][j] == ' ' || (j != 0 && map[i][j - 1] == ' ')))
				return (false);
		}
	}
	return (true);
}

static bool	validate_row(char *row)
{
	int		i;
	bool	inside;

	if (!row || !ft_strchr("1", row[0]))
		return (false);
	if (ft_strchr("0NSEW", row[0]))
		return (false);
	i = 0;
	while (row[i])
	{
		i++;
	}
	return (true);
}
