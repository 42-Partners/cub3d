/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:27:36 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/04/01 19:49:36 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <limits.h>

static void	fill_map(t_game *game, char *line, int map_fd);
static bool	add_row(t_game *game, char *row);
static void	set_map_size(t_game *game);

void	parse_map(t_game *game)
{
	char	*line;

	line = get_next_line(game->map.map_fd);
	game->map.map = ft_calloc(1, sizeof (char *));
	if (!game->map.map)
		error_exit(game, "Malloc error");
	while (line && ft_strcmp("\n", line) == 0)
	{
		free(line);
		line = get_next_line(game->map.map_fd);
	}
	fill_map(game, line, game->map.map_fd);
	set_map_size(game);
}

static void	fill_map(t_game *game, char *line, int map_fd)
{
	char	*trimmed;

	while (line)
	{
		trimmed = ft_strtrim(line, "\n");
		free(line);
		if (!trimmed)
			error_exit(game, "Malloc error");
		if (*trimmed == '\0')
		{
			free(trimmed);
			return ;
		}
		else if (!add_row(game, trimmed))
			error_exit(game, "Malloc error");
		line = get_next_line(map_fd);
	}
}

static bool	add_row(t_game *game, char *row)
{
	int		i;
	char	**new_map;

	i = 0;
	while (game->map.map[i])
		i++;
	new_map = ft_realloc(
			game->map.map, sizeof(char *) * i, sizeof(char *) * (i + 2));
	if (!new_map)
	{
		ft_free_arr(&game->map.map);
		return (false);
	}
	game->map.map = new_map;
	game->map.map[i] = row;
	game->map.map[i + 1] = NULL;
	return (true);
}

static void	set_map_size(t_game *game)
{
	int	max_x;
	int	x;
	int	y;

	y = 0;
	max_x = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x] && game->map.map[y][x] != '\n')
		{
			if (x == INT_MAX - 10)
				error_exit(game, "Map too big");
			if (x > max_x)
				max_x = x;
			x++;
		}
		if (y == INT_MAX - 10)
			error_exit(game, "Map too big");
		y++;
	}
	if (max_x < 2 || y < 2)
		error_exit(game, "Invalid map");
	game->map.rows = y;
	game->map.cols = max_x + 1;
}
